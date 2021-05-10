#pragma once

#include <Engine/Core/AEvent.hpp>



namespace engine::core::event {



class Container {

public:

    // ------------------------------------------------------------------ *structors

    explicit Container();

    ~Container();



    // ------------------------------------------------------------------ Copy sementic

    Container(
        const Container&
    ) noexcept = delete;

    auto operator=(
        const Container&
    ) noexcept -> Container& = delete;



    // ------------------------------------------------------------------ Copy sementic

    Container(
        Container&&
    ) noexcept;

    auto operator=(
        Container&&
    ) noexcept -> Container&;



    // ------------------------------------------------------------------ Emplace

    template<
        ::engine::core::event::ConceptType EventType
    > void emplace(
        auto&&... args
    );


    // ------------------------------------------------------------------ Resolver

    void resolve(
        engine::core::AScene& scene
    );



public:
protected:
protected:
private:
private:

    std::deque<std::unique_ptr<::engine::core::AEvent>> m_events;

};



} // namespace engine::core::event

#include <Engine/Core/Event/Container.impl.hpp>
