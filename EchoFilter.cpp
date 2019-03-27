#include "EchoFilter.hpp"

namespace pdal
{

static const PluginInfo s_info
{
    "filters.echo",
    "Echo something.",
    ""
};

CREATE_SHARED_STAGE(EchoFilter, s_info)

std::string EchoFilter::getName() const { return s_info.name; }

void EchoFilter::addArgs(ProgramArgs& args)
{
    args.add("value", "Thing to echo", m_value);
}

PointViewSet EchoFilter::run(PointViewPtr view)
{
    std::cout << m_value << std::endl;
    PointViewSet views;
    views.insert(view);
    return views;
}

} // namespace pdal

