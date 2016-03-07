/*
 *Copyright (c) 2013-2014, yinqiwen <yinqiwen@gmail.com>
 *All rights reserved.
 *
 *Redistribution and use in source and binary forms, with or without
 *modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Redis nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 *THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include "common/common.hpp"
#include "util/atomic.hpp"
#include "util/time_helper.hpp"
#include "thread/spin_mutex_lock.hpp"
#include "thread/lock_guard.hpp"
#include "util/string_helper.hpp"
#define ARDB_OPS_SEC_SAMPLES 16
OP_NAMESPACE_BEGIN

    struct Track
    {
            std::string Name;
            virtual void Dump(std::string& str) = 0;
            virtual ~Track()
            {
            }
    };

    struct CountTrack: public Track
    {
            volatile uint64_t count;
            CountTrack() :
                    count(0)
            {
            }
            uint64_t Add(uint64_t inc)
            {
                return atomic_add_uint64(&count, inc);
            }
            void Set(uint64_t v)
            {
                count = v;
            }
    };

    typedef uint64_t CountCallback(void* data);
    struct CountRefTrack: public Track
    {
            CountCallback* cb;
            void* cbdata;
            CountRefTrack(CountCallback* callback, void* data) :
                    cb(callback), cbdata(data)
            {
            }
    };

    struct QPSTrack: public Track
    {
            uint64_t qpsSamples[16];
            int qpsSampleIdx;
            uint64_t lastMsgCount;
            uint64_t lastSampleTime;
            uint64_t msgCount;
            QPSTrack() :
                    qpsSampleIdx(0), lastMsgCount(0), lastSampleTime(0), msgCount(0)
            {
                memset(qpsSamples, 0, sizeof(qpsSamples));
            }
            void trackQPSPerSecond()
            {
                uint64_t now = get_current_epoch_millis();
                uint64_t qps = 0;
                if (lastSampleTime == 0)
                {
                    lastSampleTime = now;
                }
                if (now > lastSampleTime)
                {
                    qps = ((msgCount - lastMsgCount) * 1000) / (now - lastSampleTime);
                }
                qpsSamples[qpsSampleIdx] = qps;
                qpsSampleIdx = (qpsSampleIdx + 1) % arraysize(qpsSamples);
                lastMsgCount = msgCount;
                lastSampleTime = now;
            }
            uint64_t QPS()
            {
                uint64_t sum = 0;
                for (int i = 0; i < arraysize(qpsSamples); i++)
                {
                    sum += qpsSamples[i];
                }
                return sum / arraysize(qpsSamples);
            }
            void IncMsgCount(uint64_t inc)
            {
                atomic_add_uint64(&msgCount, inc);
            }
            void Dump(std::string& str);
    };

    struct CostTrack: public Track
    {

    };

    class Statistics
    {
        private:
            typedef TreeMap<std::string, Track*>::Type TrackTable;
            TrackTable m_tracks;
            Statistics();
        public:
            int AddTrack(Track* track);
            static Statistics& GetSingleton();

    };

OP_NAMESPACE_END

#endif /* STATISTICS_HPP_ */
