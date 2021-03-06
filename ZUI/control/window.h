﻿/**
* @file		Windows.h
* @brief	窗体控件实现.
* @author	[Zero](22249030)
* @version	1.0
* @date		$date
* @par History:
*
* [2016-10-25] <Zero> v1.0
*
* + v1.0版发布.
*
*/
#ifndef __UIWINDOW_H__
#define __UIWINDOW_H__

#define	Proc_Window_SetNoBox		1001	//设置为无边框窗体
#define	Proc_Window_SetWindowMin	1002	//
#define	Proc_Window_SetWindowMax	1003
#define	Proc_Window_SetWindowRestor	1004
#define	Proc_Window_SetMinInfo		1005
#define	Proc_Window_SetMaxInfo		1006
#define	Proc_Window_SetSize			1007
#define	Proc_Window_SetComBo		1008
#define	Proc_Window_Popup			1009

//------宏封装
#define ZuiWindowSetNoBox(Control, ...) ZProc(Control, Window_SetNoBox, __VA_ARGS__);
#define ZuiWindowSetWindowMin(Control, ...) ZProc(Control, Window_SetWindowMin, __VA_ARGS__);
#define ZuiWindowSetWindowMax(Control, ...) ZProc(Control, Window_SetWindowMax, __VA_ARGS__);
#define ZuiWindowSetWindowRestor(Control, ...) ZProc(Control, Window_SetWindowRestor, __VA_ARGS__);
#define ZuiWindowSetMinInfo(Control, ...) ZProc(Control, Window_SetMinInfo, __VA_ARGS__);
#define ZuiWindowSetMaxInfo(Control, ...) ZProc(Control, Window_SetMaxInfo, __VA_ARGS__);
#define ZuiWindowSetSize(Control, ...) ZProc(Control, Window_SetSize, __VA_ARGS__);
#define ZuiWindowSetComBo(Control, ...) ZProc(Control, Window_SetComBo, __VA_ARGS__);
#define ZuiWindowPopup(Control, ...) ZProc(Control, Window_Popup, __VA_ARGS__);

/**窗口控件结构*/
typedef struct _ZWindow
{
	ZRect m_rect;
	ZuiBool m_nobox;
	ZuiBool m_bMax;	//是否最大化
	HWND m_hWnd;
	WNDPROC m_OldWndProc;
	ZuiControl root;
	ZuiPaintManager m_pm;
	ZCtlProc old_call;
	ZuiAny old_udata;
	ZuiBool m_combo;//组合窗口 失焦隐藏
}*ZuiWindow, ZWindow;
ZEXPORT ZuiAny ZCALL ZuiWindowProc(ZuiInt ProcId, ZuiControl cp, ZuiWindow p, ZuiAny Param1, ZuiAny Param2, ZuiAny Param3);
//查找窗口
ZEXPORT ZuiControl ZCALL ZuiWindowFindName(ZuiText Name);

#endif	//__UIWINDOW_H__