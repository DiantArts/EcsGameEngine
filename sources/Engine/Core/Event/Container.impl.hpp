#pragma once



// ------------------------------------------------------------------ Emplace

template<
    ::engine::core::event::ConceptType EventType
> void ::engine::core::event::Container::emplace(
    auto&&... args
)
{
    m_events.push_back(::std::make_unique<EventType>(::std::forward<decltype(args)>(args)...));
}
