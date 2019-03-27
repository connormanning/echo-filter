#pragma once

#include <pdal/Filter.hpp>
#include <pdal/Streamable.hpp>

#include <memory>

namespace pdal
{

class PDAL_DLL EchoFilter : public Filter
{
public:
    std::string getName() const override;
    virtual void addArgs(ProgramArgs& args) override;
    virtual PointViewSet run(PointViewPtr view) override;

private:
    std::string m_value;
};

} // namespace pdal

