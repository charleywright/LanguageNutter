#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class skills
    {
    public:
        skills(json parsed)
        {
            this->reading = get_int(parsed["reading"], "average");
            this->listening = get_int(parsed["listening"], "average");
            this->writing = get_int(parsed["writing"], "average");
            this->speaking = get_int(parsed["speaking"], "average");
            this->verbs = get_int(parsed["verbs"], "average");
            this->grammar = get_int(parsed["grammar"], "average");
            this->sentence = get_int(parsed["sentence"], "average");
        };
        double reading;
        double listening;
        double writing;
        double speaking;
        double verbs;
        double grammar;
        double sentence;
    };
}