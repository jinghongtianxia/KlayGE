// DShowFactory.cpp
// KlayGE DirectShow播放引擎抽象工厂 实现文件
// Ver 3.4.0
// 版权所有(C) 龚敏敏, 2006
// Homepage: http://klayge.sourceforge.net
//
// 3.4.0
// 初次建立 (2006.7.15)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#include <KlayGE/KlayGE.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/ShowFactory.hpp>

#include <KlayGE/DShow/DShow.hpp>
#include <KlayGE/DShow/DShowFactory.hpp>

extern "C"
{
	void MakeShowFactory(KlayGE::ShowFactoryPtr& ptr, boost::program_options::variables_map const & /*vm*/)
	{
		ptr = KlayGE::MakeSharedPtr<KlayGE::ConcreteShowFactory<KlayGE::DShowEngine> >(L"DirectShow Show Factory");
	}

	bool Match(std::string const & name, std::string const & compiler)
	{
		if (("DShow" == name) && (KLAYGE_COMPILER_TOOLSET == compiler))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
