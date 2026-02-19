#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  auto its = find_all(source.begin(), source.end(), (int(*)(int))std::isspace);
  std::vector<Token> temp;
  std::transform(its.begin(), its.end() - 1, its.begin() + 1,
                 std::back_inserter(temp),
                 [&source](auto it1, auto it2) { return Token(source, it1, it2); });
  Corpus tokens;
  std::transform(temp.begin(), temp.end(),
                 std::inserter(tokens, tokens.end()),
                 [](const Token& t) { return t; });
  std::erase_if(tokens, [](const Token& t) {
    return t.content.empty();
  });
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;

  auto to_misspelling = [&](const Token& t) {
    auto matches = dictionary
      | rv::filter([&](const std::string& w) { return levenshtein(t.content, w) == 1; });
    return Misspelling{t, std::set<std::string>(matches.begin(), matches.end())};
  };

  auto view = source
    | rv::filter([&](const Token& t) { return !dictionary.contains(t.content); })
    | rv::transform(to_misspelling)
    | rv::filter([](const Misspelling& m) { return !m.suggestions.empty(); });

  return std::set<Misspelling>(view.begin(), view.end());
}

/* Helper methods */

#include "utils.cpp"