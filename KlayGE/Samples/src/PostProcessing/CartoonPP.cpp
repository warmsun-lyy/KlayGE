#include <KlayGE/KlayGE.hpp>
#include <KlayGE/RenderEffect.hpp>

#include "CartoonPP.hpp"

using namespace KlayGE;

CartoonPostProcess::CartoonPostProcess()
		: PostProcess(L"Cartoon")
{
	input_pins_.push_back(std::make_pair("normal_depth_tex", TexturePtr()));
	input_pins_.push_back(std::make_pair("color_tex", TexturePtr()));

	this->Technique(Context::Instance().RenderFactoryInstance().LoadEffect("CartoonPP.fxml")->TechniqueByName("Cartoon"));
}

void CartoonPostProcess::InputPin(uint32_t index, TexturePtr const & tex)
{
	PostProcess::InputPin(index, tex);
	if ((0 == index) && tex)
	{
		*(technique_->Effect().ParameterByName("inv_width_height")) = float2(1.0f / tex->Width(0), 1.0f / tex->Height(0));
	}
}
