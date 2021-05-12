#pragma once

namespace engine::graphic::opengl {



class Ubo {

public:

    // ---------------------------------- *structors

    Ubo(
        size_t size,
        int index
    );
    ~Ubo();



    // ---------------------------------- Copy sementic

    Ubo(
        const Ubo&
    ) noexcept = delete;

    auto operator=(
        const Ubo&
    ) noexcept
        -> Ubo& = delete;



    // ---------------------------------- Move sementic

    Ubo(
        Ubo&&
    ) noexcept;

    auto operator=(
        Ubo&&
    ) noexcept
        -> Ubo&;



    // ---------------------------------- get

    GLuint get() const;



    // ---------------------------------- bind

    void bind() const;
    void unbind() const;



    // ---------------------------------- SubData


    template <
        typename DataType
    > void setOneSubData(
        GLintptr offset,
        DataType& data
    ) const
    {
        this->bind();
        this->setSubData(offset, data);
        this->unbind();
    }

    template <
        typename DataType
    > void setOneSubData(
        GLintptr offset,
        DataType&& data
    ) const
    {
        this->bind();
        this->setSubData(offset, data);
        this->unbind();
    }



    template <
        typename DataType
    > void setSubData(
        GLintptr offset,
        DataType& data
    ) const
    {
        // std::cout << "subdata: " << sizeof(data) << " (" << offset << ")" << std::endl;
        glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(data), &data);
    }

    template <
        typename DataType
    > void setSubData(
        GLintptr offset,
        DataType&& data
    ) const
    {
        // std::cout << "subdata: " << sizeof(data) << " (" << offset << ")" << std::endl;
        glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(data), &data);
    }



private:

    GLuint m_ubo;

};



} // namespace engine::graphic::opengl
