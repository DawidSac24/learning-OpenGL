#pragma once

#include "Event.h"
#include <concepts>
#include <memory>

namespace Core
{

class Layer
{
  public:
    virtual ~Layer() = default;

    virtual void OnEvent(Event &event)
    {
    }

    virtual void OnUpdate(float ts)
    {
    }
    virtual void OnRender()
    {
    }

    template <std::derived_from<Layer> T, typename... Args> void TransitionTo(Args &&...args)
    {
        QueueTransition(std::move(std::unique_ptr<T>(std::forward<Args>(args)...)));
    }

    Layer operator=(const Layer &other)
    {
        this = other;
        return *this;
    }

  private:
    void QueueTransition(std::unique_ptr<Layer> layer);
};
} // namespace Core
