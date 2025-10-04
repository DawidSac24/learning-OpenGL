#include "Layer.h"

#include "Application.h"

namespace Core
{
void Layer::QueueTransition(std::unique_ptr<Layer> toLayer)
{
    auto &layerStack = Application::Get().GetLayerStack();
    for (auto &layer : layerStack)
    {
        if (layer.get() == this)
        {
            layer = std::move(toLayer);
            return;
        }
    }
}
} // namespace Core
