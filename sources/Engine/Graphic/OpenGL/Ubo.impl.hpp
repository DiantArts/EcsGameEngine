#pragma once



template <
    typename DataType
> void ::engine::graphic::opengl::Ubo::setOneSubData(
    ::std::size_t offset,
    const DataType& data
) const
{
    this->bind();
    this->setSubData(offset, data);
}

template <
    typename DataType
> inline void ::engine::graphic::opengl::Ubo::setSubData(
    ::std::size_t offset,
    const DataType& data
)
{
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(data), &data);
}
