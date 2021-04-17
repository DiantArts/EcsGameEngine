#pragma once

#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/Component/Container.hpp>



namespace engine::ecs::system {


template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> class System {

public:

    // using Type = void(*)(FuncType);

    using SignatureType = ::std::bitset<::engine::ecs::component::Container::getMaxComponentID()>;



public:

    // ------------------------------------------------------------------ *structors

    System(void(&func)(ComponentTypes...));

    ~System();



    // ------------------------------------------------------------------ Run

    void operator()();

    void run();



    // ------------------------------------------------------------------ Signature

    const System::SignatureType& getSignature() const;



private:

    void(*m_func)(ComponentTypes...);

    System::SignatureType m_signature;

};



} // namespace engine::ecs::system
