
#ifndef WIIMOTE_CONFIG_DIAG_H
#define WIIMOTE_CONFIG_DIAG_H

#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>

#include "InputConfigDiag.h"
#include "ConfigManager.h"

class WiimoteConfigPage : public wxNotebookPage
{
public:
	WiimoteConfigPage(wxWindow* const parent, const int index);

	void SelectSource(wxCommandEvent& event);
	void UpdateWiimoteStatus();
	void RevertSource();

	wxStaticText*	connected_wiimotes_txt;

private:
	const int	m_index;
	unsigned int orig_source;
};

class WiimoteGeneralConfigPage : public wxPanel
{
public:
	WiimoteGeneralConfigPage(wxWindow* const parent);

	void OnSensorBarPos(wxCommandEvent& event)
	{
		SConfig::GetInstance().m_SYSCONF->SetData("BT.BAR", event.GetInt());
		event.Skip();
	}
	void OnSensorBarSensitivity(wxCommandEvent& event)
	{
		SConfig::GetInstance().m_SYSCONF->SetData("BT.SENS", event.GetInt());
		event.Skip();
	}
	void OnSpeakerVolume(wxCommandEvent& event)
	{
		SConfig::GetInstance().m_SYSCONF->SetData("BT.SPKV", event.GetInt());
		event.Skip();
	}
	void OnMotor(wxCommandEvent& event)
	{
		SConfig::GetInstance().m_SYSCONF->SetData("BT.MOT", event.GetInt());
		event.Skip();
	}
	void OnReconnectOnLoad(wxCommandEvent& event)
	{
		SConfig::GetInstance().m_WiimoteReconnectOnLoad = event.GetInt();
		event.Skip();
	}

private:
};

class WiimoteConfigDiag : public wxDialog
{
public:
	WiimoteConfigDiag(wxWindow* const parent, InputPlugin& plugin);

#ifdef _WIN32
	void PairUpRealWiimotes(wxCommandEvent& event);
#endif
	void RefreshRealWiimotes(wxCommandEvent& event);
	
	void ConfigEmulatedWiimote(wxCommandEvent& event);
	void Save(wxCommandEvent& event);
	void UpdateGUI();

private:
	void Cancel(wxCommandEvent& event);

	InputPlugin&	m_plugin;
	wxNotebook*		m_pad_notebook;
	std::vector<WiimoteConfigPage*> m_wiimote_config_pages;
};


#endif
