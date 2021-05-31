//
// Akanya, Engine
// libraries/Tools/Iterator
// help to create Iterators
//

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___

#include <iterator>



namespace tool {



template <
    typename TypeToIterate,
    typename IteratorCategory = ::std::contiguous_iterator_tag
> class Iterator {

public:

    class iterator {

    public:

        using iterator_category = IteratorCategory;
        using difference_type   = ::std::ptrdiff_t;
        using value_type        = TypeToIterate;
        using pointer           = value_type*;
        using reference         = value_type&;

        explicit iterator(const pointer ptr) : m_ptr(::std::move(ptr))
        {}

        [[ nodiscard ]] auto operator*()
            -> iterator::reference
        {
            return *m_ptr;
        }

        [[ nodiscard ]] auto operator->()
            -> iterator::pointer
        {
            return m_ptr;
        }

        [[ nodiscard ]] auto operator++()
            -> iterator&
        {
            m_ptr++;
            return *this;
        }

        [[ nodiscard ]] auto operator++(int)
            -> iterator
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        [[ nodiscard ]] auto operator==(
            const iterator& that
        )
            -> bool
        {
            return m_ptr == that.m_ptr;
        }

        [[ nodiscard ]] auto operator!=(
            const iterator& that
        )
            -> bool
        {
            return m_ptr != that.m_ptr;
        }

    private:

        iterator::pointer m_ptr;

    };

    class const_iterator {

    public:

        using iterator_category = IteratorCategory;
        using difference_type   = ::std::ptrdiff_t;
        using value_type        = TypeToIterate;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        const_iterator(pointer ptr) : m_ptr(::std::move(ptr))
        {}

        [[ nodiscard ]] reference operator*()
        {
            return *m_ptr;
        }

        [[ nodiscard ]] pointer operator->()
        {
            return m_ptr;
        }

        [[ nodiscard ]] const const_iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        [[ nodiscard ]] const const_iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        [[ nodiscard ]] bool operator==(const Iterator::const_iterator& that)
        {
            return m_ptr == that.m_ptr;
        }

        [[ nodiscard ]] bool operator!=(const Iterator::const_iterator& that)
        {
            return m_ptr != that.m_ptr;
        }

    private:

        pointer m_ptr;

    };
};


} // namespace tool



#endif // ___INCLUDE_GUARD_LIBRARIES_TOOLS_ITERATOR_HPP___
