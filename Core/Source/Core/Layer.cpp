#include "Layer.h"

#include "Application.h"

namespace Core
{
void Layer::QueueTransition(std::unique_ptr<Layer> layer)
{
    auto &layerStack = Application::Get().m_LayerStack;
}
} // namespace Core
