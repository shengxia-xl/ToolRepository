/*******************************************************************
* 文件名称：CImageEditEventRegister.h
* 作者姓名：徐立
* 文件描述：图像操作器注册类
* 需求版本：
* 创建时间：2019-5-20
* Copyright (C) 江西博微新技术有限公司 All rights reserved
*******************************************************************/
#pragma once
template<typename T>
class CImageEditEventRegister
{
public:
	CImageEditEventRegister()
	{
		IImageEditEvent *pImageEditEvent = new T;
		ImageEditEventManager::GetInst()->AddEvent(pImageEditEvent);

		return;
	}
};

#define REGISTER_IMAGEEDITEVENT(ClassName) \
	static CImageEditEventRegister<ClassName> REGISTAR_##ClassName;

	
	
	void ImageEditEventManager::AddEvent(IImageEditEvent* pEditEvent)
{
	if (pEditEvent == nullptr)
		return;

	ImageEditType editType = pEditEvent->GetEditType();
	auto itMap = _mapType2EditEvent.find(editType);

	if (itMap != _mapType2EditEvent.end()) // 已经添加
	{
		ATLASSERT(FALSE);
		return;
	}

	_vImageEditEvent.push_back(pEditEvent);
	_mapType2EditEvent[editType] = pEditEvent;

}




std::map<ImageEditType, IImageEditEvent *> _mapType2EditEvent;
	std::vector<IImageEditEvent *> _vImageEditEvent;