#pragma once
#include <string>
#include <vector>
namespace texo::tooling {
struct editor_measurement_v1{std::string operation,language,temperature,size;double milliseconds=0;};
struct editor_budget_v1{std::string operation;double p95_ms=0;};
[[nodiscard]] double percentile95_v1(std::vector<double> samples);
[[nodiscard]] bool meets_editor_budgets_v1(const std::vector<editor_measurement_v1>&,const std::vector<editor_budget_v1>&);
} // namespace texo::tooling
