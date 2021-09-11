#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class skills
    {
    public:
        skills(json parsed)
        {
            if (parsed["reading"]["average"].type_name() == "null")
                parsed["reading"]["average"] = "0";
            this->reading = std::stod(parsed["reading"].value("average", ""));
            if (parsed["listening"]["average"].type_name() == "null")
                parsed["listening"]["average"] = "0";
            this->listening = std::stod(parsed["listening"].value("average", ""));
            if (parsed["writing"]["average"].type_name() == "null")
                parsed["writing"]["average"] = "0";
            this->writing = std::stod(parsed["writing"].value("average", ""));
            if (parsed["speaking"]["average"].type_name() == "null")
                parsed["speaking"]["average"] = "0";
            this->speaking = std::stod(parsed["speaking"].value("average", ""));
            if (parsed["verbs"]["average"].type_name() == "null")
                parsed["verbs"]["average"] = "0";
            this->verbs = std::stod(parsed["verbs"].value("average", ""));
            if (parsed["grammar"]["average"].type_name() == "null")
                parsed["grammar"]["average"] = "0";
            this->grammar = std::stod(parsed["grammar"].value("average", ""));
            if (parsed["sentence"]["average"].type_name() == "null")
                parsed["sentence"]["average"] = "0";
            this->sentence = std::stod(parsed["sentence"].value("average", ""));
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