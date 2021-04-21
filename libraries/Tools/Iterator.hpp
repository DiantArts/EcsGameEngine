//
// Akanya, Engine
// libraries/Tools/Iterator
// help to create Iterators
//

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___

#include <iterator>



namespace tool {



template <typename TypeToIterate, typename IteratorCategory = std::contiguous_iterator_tag>
class Iterator {
public:
    class iterator {
    public:
        using iterator_category = IteratorCategory;
        using difference_type   = std::ptrdiff_t;
        using value_type        = TypeToIterate;
        using pointer           = value_type*;
        using reference         = value_type&;

        explicit iterator(const pointer ptr) : m_ptr(std::move(ptr))
        {}

        reference operator*()
        {
            return *m_ptr;
        }

        pointer operator->()
        {
            return m_ptr;
        }

        iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator::iterator& that)
        {
            return m_ptr == that.m_ptr;
        }

        bool operator!=(const Iterator::iterator& that)
        {
            return m_ptr != that.m_ptr;
        }

    private:
        pointer m_ptr;
    };

    class const_iterator {
    public:
        using iterator_category = IteratorCategory;
        using difference_type   = std::ptrdiff_t;
        using value_type        = TypeToIterate;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        const_iterator(pointer ptr) : m_ptr(std::move(ptr))
        {}

        reference operator*()
        {
            return *m_ptr;
        }

        pointer operator->()
        {
            return m_ptr;
        }

        const const_iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        const const_iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator::const_iterator& that)
        {
            return m_ptr == that.m_ptr;
        }

        bool operator!=(const Iterator::const_iterator& that)
        {
            return m_ptr != that.m_ptr;
        }

    private:
        pointer m_ptr;
    };

    // virtual Iterator::iterator       begin()        = 0;
    // virtual Iterator::const_iterator begin() const  = 0;
    // virtual Iterator::const_iterator cbegin() const = 0;

    // virtual Iterator::iterator       end()        = 0;
    // virtual Iterator::const_iterator end() const  = 0;
    // virtual Iterator::const_iterator cend() const = 0;
};


} // namespace tool



#endif // ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___
