#include "eval.hpp"

#include <iostream>

using klmr::lisp::value;
using klmr::lisp::environment;

auto read(std::string const& input) -> value {
    (void) input;
    return klmr::lisp::symbol{"lambda"}; // FIXME placeholder
}

auto get_global_environment() -> environment {
    using klmr::lisp::symbol;
    auto env = environment{};
    env.set(symbol{"lambda"}, symbol{"#lambda"});
    return env;
}

auto repl(std::string prompt) -> void {
    auto input = std::string{};
    auto global_env = get_global_environment();
    std::cout << prompt << std::flush;
    // input ruminations ...
    std::cout << '\n';
    auto&& result = eval(read(input), global_env);
    std::cout << result << '\n';
}

auto main() -> int
try {
    repl(">>> ");
} catch (char const* msg) {
    std::cerr << msg << '\n';
    return 1;
}
