#pragma once

#define START_COMPONENT_DECLARATIONS() \
    namespace engine::ecs::component::declaration::detail { \
        template <typename> class WithID; \
        constexpr const ::std::size_t baseIDCounter { __COUNTER__ + 1 }; \
    } \
    class RandomAndTotallyUnexistantVarThatJustIsUsefulForTheSumicolon

#define DECLARE_COMPONENT(className) \
    class className; \
    template <> \
    class engine::ecs::component::declaration::detail::WithID<className> { \
    public: \
        static inline constexpr ::std::size_t getID() { return m_id; } \
    private: \
        static constexpr auto m_id { __COUNTER__ - ecs::declaration::detail::baseIDCounter }; \
    }

#define DECLARE_COMPONENT_IN_NAMESPACE(namespaceName, className) \
    namespace namespaceName { class className; } \
    template <> \
    class engine::ecs::component::declaration::detail::WithID<namespaceName::className> { \
    public: \
        static inline constexpr ::std::size_t getID() { return m_id; } \
    private: \
        static constexpr auto m_id { __COUNTER__ - ::engine::ecs::component::declaration::detail::baseIDCounter }; \
    }

#define STOP_COMPONENT_DECLARATIONS() \
    namespace engine::ecs::component::declaration::detail { \
        constexpr const ::std::size_t numberOfIDs \
            { __COUNTER__ - ::engine::ecs::component::declaration::detail::baseIDCounter }; \
    } \
    class RandomAndTotallyUnexistantVarThatJustIsUsefulForTheSumicolon
