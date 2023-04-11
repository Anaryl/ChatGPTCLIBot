//
// Created by v2ray on 2023/3/13.
//

#ifndef GPT3BOT_NETWORK_H
#define GPT3BOT_NETWORK_H

#include "boost/algorithm/string/regex.hpp"
#include "../util/PromptUtils.h"
#include "../util/TermUtils.h"

namespace api {

    class TimeoutChecker {
        long long creation_time;
        const unsigned int timeout_ms_;

    public:
        explicit TimeoutChecker(const unsigned int& timeout_ms);
        virtual ~TimeoutChecker();

        [[nodiscard]] long long calc_next() const;
        void reset_creation_time();
    };

    bool call_api(const std::string& initial_prompt, const std::vector<std::shared_ptr<chat::Exchange>>& chat_exchanges,
                  const std::string& api_key, const std::string& model, const float& temperature, const int& max_tokens,
                  const float& top_p, const float& frequency_penalty, const float& presence_penalty,
                  const std::unordered_map<uint16_t, float>& logit_bias,
                  const unsigned int& max_short_memory_length, const unsigned int& max_reference_length,
                  const std::string& me_id, const std::string& bot_id, std::function<void(const std::string& streamed_response)> callback,
                  const bool& debug_reference = false, const bool& pause_when_showing_reference = true);
    bool is_new_api(const std::string& model_name);
} // api

#endif //GPT3BOT_NETWORK_H
