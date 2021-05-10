#pragma once

namespace engine::core { class AScene; }



namespace engine::core::event {



class AEvent {

public:

    // ------------------------------------------------------------------ *structors

    explicit AEvent();

    virtual ~AEvent() = 0;



    // ------------------------------------------------------------------ Resolver

    virtual void resolve(
        engine::core::AScene& scene
    ) = 0;



public:
protected:
protected:
private:
private:

};



template <
    typename EventType
> concept ConceptType =
    std::derived_from<::std::remove_cvref_t<EventType>, ::engine::core::event::AEvent>;



} // namespace engine::core::event
