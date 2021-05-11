#include <pch.hpp>
#include <Engine/Core/AWindow.hpp>

// ------------------------------------------------------------------ *structors

::engine::core::AWindow::AWindow()
    : m_size{ 1920, 1080 }
{}

::engine::core::AWindow::~AWindow() = default;



// ------------------------------------------------------------------ Move sementic

::engine::core::AWindow::AWindow(
    AWindow&&
) noexcept = default;

auto ::engine::core::AWindow::operator=(
    AWindow&&
) noexcept
    -> AWindow& = default;



// ------------------------------------------------------------------ Size

auto ::engine::core::AWindow::getSize() const
    -> const AWindow::Size&
{
    return m_size;
}
