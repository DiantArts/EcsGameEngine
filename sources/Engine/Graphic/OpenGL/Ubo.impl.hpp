#pragma once



template <
    typename DataType
> void ::engine::graphic::opengl::Ubo::setOneSubData(
    ::GLintptr offset,
    const DataType& data
) const
{
    this->bind();
    this->setSubData(offset, data);
}

template <
    typename DataType
> void ::engine::graphic::opengl::Ubo::setSubData(
    ::GLintptr offset,
    const DataType& data
) const
{
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(data), &data);
}
