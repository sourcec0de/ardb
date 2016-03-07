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
#include "db/db.hpp"
#include <float.h>

OP_NAMESPACE_BEGIN

    int Ardb::ZAdd(Context& ctx, RedisCommandFrame& cmd)
    {
        return 0;
    }

    int Ardb::ZCard(Context& ctx, RedisCommandFrame& cmd)
    {
        return ObjectLen(ctx, KEY_ZSET, cmd.GetArguments()[0]);
    }

    int Ardb::ZCount(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZIncrby(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRange(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }
    int Ardb::ZRevRange(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }


    int Ardb::ZRangeByScore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRevRangeByScore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRank(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRevRank(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRem(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRemRangeByRank(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRemRangeByScore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZInterStore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZUnionStore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZScan(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZScore(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZLexCount(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRangeByLex(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

    int Ardb::ZRemRangeByLex(Context& ctx, RedisCommandFrame& cmd)
    {

        return 0;
    }

OP_NAMESPACE_END
