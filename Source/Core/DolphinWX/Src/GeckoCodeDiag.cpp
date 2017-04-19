
#include "GeckoCodeDiag.h"

//#include <SFML/Network/Http.hpp>

#include <sstream>

#define _connect_macro_(b, f, c, s)	(b)->Connect(wxID_ANY, (c), wxCommandEventHandler(f), (wxObject*)0, (wxEvtHandler*)s)

namespace Gecko
{

static const wxString wxstr_name(wxTRANSLATE("Name: ")),
	wxstr_notes(wxTRANSLATE("Notes: ")),
	wxstr_creator(wxTRANSLATE("Creator: "));

CodeConfigPanel::CodeConfigPanel(wxWindow* const parent)
	: wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize)
{
	m_listbox_gcodes = new wxCheckListBox(this, -1, wxDefaultPosition, wxDefaultSize);
	_connect_macro_(m_listbox_gcodes, CodeConfigPanel::UpdateInfoBox, wxEVT_COMMAND_LISTBOX_SELECTED, this);
	_connect_macro_(m_listbox_gcodes, CodeConfigPanel::ToggleCode, wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, this);

	m_infobox.label_name = new wxStaticText(this, -1, wxGetTranslation(wxstr_name));
	m_infobox.label_creator = new wxStaticText(this, -1, wxGetTranslation(wxstr_creator));
	m_infobox.label_notes = new wxStaticText(this, -1, wxGetTranslation(wxstr_notes));
	m_infobox.textctrl_notes = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxSize(64, -1), wxTE_MULTILINE | wxTE_READONLY);
	m_infobox.listbox_codes = new wxListBox(this, -1, wxDefaultPosition, wxSize(-1, 64));

	// TODO: buttons to add/edit codes

	// sizers
	wxBoxSizer* const sizer_infobox = new wxBoxSizer(wxVERTICAL);
	sizer_infobox->Add(m_infobox.label_name, 0, wxBOTTOM, 5);
	sizer_infobox->Add(m_infobox.label_creator, 0,  wxBOTTOM, 5);
	sizer_infobox->Add(m_infobox.label_notes, 0, wxBOTTOM, 5);
	sizer_infobox->Add(m_infobox.textctrl_notes, 0, wxBOTTOM | wxEXPAND, 5);
	sizer_infobox->Add(m_infobox.listbox_codes, 1, wxEXPAND, 5);

	// button sizer
	wxBoxSizer* const sizer_buttons = new wxBoxSizer(wxHORIZONTAL);
	wxButton* const btn_download = new wxButton(this, -1, _("Download Codes (WiiRD Database)"), wxDefaultPosition, wxSize(128, -1));
	_connect_macro_(btn_download, CodeConfigPanel::DownloadCodes, wxEVT_COMMAND_BUTTON_CLICKED, this);
	sizer_buttons->AddStretchSpacer(1);
	sizer_buttons->Add(btn_download, 1, wxEXPAND);

	// horizontal sizer
	wxBoxSizer* const sizer_vert = new wxBoxSizer(wxVERTICAL);
	sizer_vert->Add(sizer_infobox, 1, wxEXPAND);
	sizer_vert->Add(sizer_buttons, 0, wxEXPAND | wxTOP, 5);
	
	wxBoxSizer* const sizer_main = new wxBoxSizer(wxVERTICAL);
	sizer_main->Add(m_listbox_gcodes, 1, wxALL | wxEXPAND, 5);
	sizer_main->Add(sizer_vert, 0, wxALL | wxEXPAND, 5);

	SetSizerAndFit(sizer_main);
}

void CodeConfigPanel::UpdateCodeList()
{
	m_listbox_gcodes->Clear();
	// add the codes to the listbox
	std::vector<GeckoCode>::const_iterator
		gcodes_iter = m_gcodes.begin(),
		gcodes_end = m_gcodes.end();
	for (; gcodes_iter!=gcodes_end; ++gcodes_iter)
	{
		m_listbox_gcodes->Append(wxString::FromAscii(gcodes_iter->name.c_str()));
		if (gcodes_iter->enabled)
			m_listbox_gcodes->Check(m_listbox_gcodes->GetCount()-1, true);
	}
	
	wxCommandEvent evt;
	UpdateInfoBox(evt);
}

void CodeConfigPanel::LoadCodes(const IniFile& inifile, const std::string& gameid)
{
	m_gameid = gameid;

	m_gcodes.clear();
	Gecko::LoadCodes(inifile, m_gcodes);

	UpdateCodeList();
}

void CodeConfigPanel::ToggleCode(wxCommandEvent& evt)
{
	const int sel = evt.GetInt();	// this right?
	if (sel > -1)
		m_gcodes[sel].enabled = m_listbox_gcodes->IsChecked(sel);
}

void CodeConfigPanel::UpdateInfoBox(wxCommandEvent&)
{
	m_infobox.listbox_codes->Clear();
	const int sel = m_listbox_gcodes->GetSelection();

	if (sel > -1)
	{
		m_infobox.label_name->SetLabel(wxGetTranslation(wxstr_name) + wxString::FromAscii(m_gcodes[sel].name.c_str()));

		// notes textctrl
		m_infobox.textctrl_notes->Clear();
		std::vector<std::string>::const_iterator
			notes_iter = m_gcodes[sel].notes.begin(),
			notes_end = m_gcodes[sel].notes.end();
		for (; notes_iter!=notes_end; ++notes_iter)
			m_infobox.textctrl_notes->AppendText(wxString::FromAscii(notes_iter->c_str()));
		m_infobox.textctrl_notes->ScrollLines(-99);	// silly

		m_infobox.label_creator->SetLabel(wxGetTranslation(wxstr_creator) + wxString::FromAscii(m_gcodes[sel].creator.c_str()));

		// add codes to info listbox
		std::vector<GeckoCode::Code>::const_iterator
		codes_iter = m_gcodes[sel].codes.begin(),
		codes_end = m_gcodes[sel].codes.end();
		for (; codes_iter!=codes_end; ++codes_iter)
			m_infobox.listbox_codes->Append(wxString::Format(wxT("%08X %08X"), codes_iter->address, codes_iter->data));
	}
	else
	{
		m_infobox.label_name->SetLabel(wxGetTranslation(wxstr_name));
		m_infobox.textctrl_notes->Clear();
		m_infobox.label_creator->SetLabel(wxGetTranslation(wxstr_creator));
	}
}

//void CodeConfigPanel::ApplyChanges(wxCommandEvent&)
//{
//	Gecko::SetActiveCodes(m_gcodes);
//}

void CodeConfigPanel::DownloadCodes(wxCommandEvent&)
{
	PanicAlertT("This feature is unavailable in this build.");
}

}

