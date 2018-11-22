#ifndef __STRING_UTILS_HPP__
#define __STRING_UTILS_HPP__

template<
  class CharT,
  class Traits = std::char_traits<CharT>,
  class Allocator = std::allocator<CharT> 
> class CustomString {
public:
  using allocator_type = Allocator;
  using value_type = typename Allocator::value_type;
  using reference = typename Allocator::reference;
  using const_reference = typename Allocator::const_reference;
  using difference_type = typename Allocator::difference_type;
  using size_type = typename Allocator::difference_type;

  class iterator {
  public:
    using difference_type = typename Allocator::difference_type;
    using value_type = typename Allocator::value_type;
    using reference = typename Allocator::reference;
    using pointer = typename Allocator::pointer;
    using iterator_category = std::random_access_iterator_tag;

    iterator();
    iterator(const iterator&);
    ~iterator();

  protected:
  private:
  };

  class const_iterator {
  public:
  protected:
  private:
  };
protected:
private:
  std::string data;
};

using String = CustomString<char>;
#endif // __STRING_UTILS_HPP__
