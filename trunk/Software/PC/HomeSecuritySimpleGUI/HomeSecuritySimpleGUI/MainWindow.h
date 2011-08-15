#pragma once
#include "HomeSecurityConfig.h"
#include <vcclr.h>

namespace HomeSecuritySimpleGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	HomeSecurityConfig* HSconfig;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();

			HSconfig = new HomeSecurityConfig();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loadX10Conf_button;
	protected: 
	private: System::Windows::Forms::Button^  editX10conf_button;
	private: System::Windows::Forms::StatusStrip^  statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel;
	private: System::Windows::Forms::Button^  programConf_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  turnOnLamp_Button;
	private: System::Windows::Forms::Button^  turnOfLamp_button;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loadX10Conf_button = (gcnew System::Windows::Forms::Button());
			this->editX10conf_button = (gcnew System::Windows::Forms::Button());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->programConf_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->turnOnLamp_Button = (gcnew System::Windows::Forms::Button());
			this->turnOfLamp_button = (gcnew System::Windows::Forms::Button());
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// loadX10Conf_button
			// 
			this->loadX10Conf_button->Location = System::Drawing::Point(13, 26);
			this->loadX10Conf_button->Name = L"loadX10Conf_button";
			this->loadX10Conf_button->Size = System::Drawing::Size(136, 23);
			this->loadX10Conf_button->TabIndex = 0;
			this->loadX10Conf_button->Text = L"Load X10 Configuration";
			this->loadX10Conf_button->UseVisualStyleBackColor = true;
			this->loadX10Conf_button->Click += gcnew System::EventHandler(this, &MainWindow::loadX10Conf_button_Click);
			// 
			// editX10conf_button
			// 
			this->editX10conf_button->Enabled = false;
			this->editX10conf_button->Location = System::Drawing::Point(13, 56);
			this->editX10conf_button->Name = L"editX10conf_button";
			this->editX10conf_button->Size = System::Drawing::Size(136, 23);
			this->editX10conf_button->TabIndex = 1;
			this->editX10conf_button->Text = L"Edit X10 Configuration";
			this->editX10conf_button->UseVisualStyleBackColor = true;
			this->editX10conf_button->Click += gcnew System::EventHandler(this, &MainWindow::editX10conf_button_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel});
			this->statusStrip->Location = System::Drawing::Point(0, 119);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(326, 22);
			this->statusStrip->TabIndex = 2;
			this->statusStrip->Text = L"Ready";
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Size = System::Drawing::Size(39, 17);
			this->toolStripStatusLabel->Text = L"Ready";
			// 
			// programConf_button
			// 
			this->programConf_button->Enabled = false;
			this->programConf_button->Location = System::Drawing::Point(13, 86);
			this->programConf_button->Name = L"programConf_button";
			this->programConf_button->Size = System::Drawing::Size(136, 23);
			this->programConf_button->TabIndex = 3;
			this->programConf_button->Text = L"Program STK500";
			this->programConf_button->UseVisualStyleBackColor = true;
			this->programConf_button->Click += gcnew System::EventHandler(this, &MainWindow::programConf_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"AVR Test Program 1:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(173, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"AVR Test Program 2:";
			// 
			// turnOnLamp_Button
			// 
			this->turnOnLamp_Button->Location = System::Drawing::Point(176, 26);
			this->turnOnLamp_Button->Name = L"turnOnLamp_Button";
			this->turnOnLamp_Button->Size = System::Drawing::Size(137, 23);
			this->turnOnLamp_Button->TabIndex = 6;
			this->turnOnLamp_Button->Text = L"Turn On Lamp";
			this->turnOnLamp_Button->UseVisualStyleBackColor = true;
			this->turnOnLamp_Button->Click += gcnew System::EventHandler(this, &MainWindow::turnOnLamp_Button_Click);
			// 
			// turnOfLamp_button
			// 
			this->turnOfLamp_button->Location = System::Drawing::Point(176, 56);
			this->turnOfLamp_button->Name = L"turnOfLamp_button";
			this->turnOfLamp_button->Size = System::Drawing::Size(137, 23);
			this->turnOfLamp_button->TabIndex = 7;
			this->turnOfLamp_button->Text = L"Turn Off Lamp";
			this->turnOfLamp_button->UseVisualStyleBackColor = true;
			this->turnOfLamp_button->Click += gcnew System::EventHandler(this, &MainWindow::turnOfLamp_button_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 141);
			this->Controls->Add(this->turnOfLamp_button);
			this->Controls->Add(this->turnOnLamp_Button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->programConf_button);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->editX10conf_button);
			this->Controls->Add(this->loadX10Conf_button);
			this->Name = L"MainWindow";
			this->Text = L"HomeSecurity";
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadX10Conf_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				OpenFileDialog ^ dialog = gcnew OpenFileDialog();
				dialog->DefaultExt = L"xml";
				dialog->Filter = L"Configuration File (*.xml)|*.xml|All files (*.*)|*.*";
				dialog->AddExtension = true;

				if(dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					//Convert string
					wchar_t path[_MAX_PATH];
					{
						pin_ptr<const wchar_t> wch = PtrToStringChars(dialog->FileName);
						wcscpy_s(path, _MAX_PATH, wch);
					}
					//Load configuration
					if(!HSconfig->loadConf(path))
					{
						MessageBox::Show("Configuration Load Failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else
					{
						toolStripStatusLabel->Text = "Configuration Loaded";
						editX10conf_button->Enabled = true;
						programConf_button->Enabled = true;
					}
				}
			 }
	private: System::Void editX10conf_button_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MessageBox::Show("This feature has not been implemented yet", "Not implemented", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			 }
private: System::Void programConf_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 	if(!HSconfig->programConf(HSconfig->getDeviceList(), COM_PORT_NO, BAUD_RATE))
				{
					MessageBox::Show("Programming Failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					toolStripStatusLabel->Text = "Programming Succeeded";
				}
		 }
private: System::Void turnOnLamp_Button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 HSconfig->sendByteSerial(0xAA);
			 toolStripStatusLabel->Text = "Turn on command sent to AVR";
		 }
private: System::Void turnOfLamp_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 HSconfig->sendByteSerial(0xFF);
			 toolStripStatusLabel->Text = "Turn off command sent to AVR";
		 }
};
}

