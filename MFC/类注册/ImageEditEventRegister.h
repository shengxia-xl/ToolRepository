/*******************************************************************
* �ļ����ƣ�CImageEditEventRegister.h
* ��������������
* �ļ�������ͼ�������ע����
* ����汾��
* ����ʱ�䣺2019-5-20
* Copyright (C) ������΢�¼������޹�˾ All rights reserved
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

	if (itMap != _mapType2EditEvent.end()) // �Ѿ����
	{
		ATLASSERT(FALSE);
		return;
	}

	_vImageEditEvent.push_back(pEditEvent);
	_mapType2EditEvent[editType] = pEditEvent;

}




std::map<ImageEditType, IImageEditEvent *> _mapType2EditEvent;
	std::vector<IImageEditEvent *> _vImageEditEvent;