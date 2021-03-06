#include "containers.h"
#include <unordered_set>
#include <locale>


namespace
{
  std::wstring to_lower(std::wstring const& s)
  {
    std::wstring ret{};
    for (auto& chr : s) ret += towlower(chr);
    return ret;
  }
}

void remove_element(std::vector<int>& v, const int index)
{
  v.erase(v.cbegin() + index);
}

void input_element(std::vector<std::wstring>& v, const int index, const std::wstring& value)
{
  v.insert(v.cbegin() + index, value);
}

int list_nth_element(const std::list<int>& c, const int index)
{
  auto it = c.cbegin();
  std::advance(it, index);
  return *it;
}

void list_sort_desc(std::list<int>& c)
{
  c.sort(std::greater<>());
}

int unique_numbers(std::wistream& ins)
{
  std::unordered_set<int> set{};
  int n{};

  while (ins >> n) set.emplace(n);
  return set.size();
}

word_frequency::word_frequency(std::wistream& in)
{
  std::wstring s{};
  while (in >> s)
  {
    freq_[to_lower(s)] += 1;
  }
}

int word_frequency::frequency(const std::wstring& s)
{
  const auto find_s = freq_.find(to_lower(s));
  return find_s != freq_.end() ? find_s->second : 0;
}

int word_frequency::count() const noexcept
{
  return freq_.size();
}
