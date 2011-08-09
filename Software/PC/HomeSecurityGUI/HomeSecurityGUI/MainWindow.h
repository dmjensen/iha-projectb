#pragma once

namespace HomeSecurityGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::ListBox^  DevicesListBox;
	private: System::Windows::Forms::ListBox^  EventsListBox;
	protected: 

	protected: 

	private: System::Windows::Forms::MenuStrip^  TopMenu;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;

	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;
	private: System::Windows::Forms::Button^  NewDeviceButton;
	private: System::Windows::Forms::Label^  DevicesLabel;
	private: System::Windows::Forms::Label^  EventLabel;
	private: System::Windows::Forms::Label^  DeviceDataLabel;
	private: System::Windows::Forms::TextBox^  DeviceIDTextBox;





	private: System::Windows::Forms::Label^  DeviceIDLabel;
	private: System::Windows::Forms::Label^  EventDataLabel;
	private: System::Windows::Forms::Label^  EventTypeLabel;
	private: System::Windows::Forms::Label^  EventHourLabel;
	private: System::Windows::Forms::Label^  EventMinuteLabel;
	private: System::Windows::Forms::ComboBox^  EventTypeComboBox;








	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;

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
			this->DevicesListBox = (gcnew System::Windows::Forms::ListBox());
			this->EventsListBox = (gcnew System::Windows::Forms::ListBox());
			this->TopMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->NewDeviceButton = (gcnew System::Windows::Forms::Button());
			this->DevicesLabel = (gcnew System::Windows::Forms::Label());
			this->EventLabel = (gcnew System::Windows::Forms::Label());
			this->DeviceDataLabel = (gcnew System::Windows::Forms::Label());
			this->DeviceIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DeviceIDLabel = (gcnew System::Windows::Forms::Label());
			this->EventDataLabel = (gcnew System::Windows::Forms::Label());
			this->EventTypeLabel = (gcnew System::Windows::Forms::Label());
			this->EventHourLabel = (gcnew System::Windows::Forms::Label());
			this->EventMinuteLabel = (gcnew System::Windows::Forms::Label());
			this->EventTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->TopMenu->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DevicesListBox
			// 
			this->DevicesListBox->FormattingEnabled = true;
			this->DevicesListBox->Location = System::Drawing::Point(152, 62);
			this->DevicesListBox->Name = L"DevicesListBox";
			this->DevicesListBox->Size = System::Drawing::Size(120, 264);
			this->DevicesListBox->TabIndex = 0;
			this->DevicesListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::DevicesListBox_SelectedIndexChanged);
			// 
			// EventsListBox
			// 
			this->EventsListBox->FormattingEnabled = true;
			this->EventsListBox->Location = System::Drawing::Point(306, 62);
			this->EventsListBox->Name = L"EventsListBox";
			this->EventsListBox->Size = System::Drawing::Size(120, 264);
			this->EventsListBox->TabIndex = 1;
			// 
			// TopMenu
			// 
			this->TopMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
			this->TopMenu->Location = System::Drawing::Point(0, 0);
			this->TopMenu->Name = L"TopMenu";
			this->TopMenu->Size = System::Drawing::Size(658, 24);
			this->TopMenu->TabIndex = 2;
			this->TopMenu->Text = L"TopMenu";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->fileToolStripMenuItem, 
				this->loadToolStripMenuItem, this->saveToolStripMenuItem, this->quitToolStripMenuItem});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItem1->Text = L"File";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->fileToolStripMenuItem->Text = L"New";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 340);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(658, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(39, 17);
			this->toolStripStatusLabel1->Text = L"Ready";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &MainWindow::toolStripStatusLabel1_Click);
			// 
			// NewDeviceButton
			// 
			this->NewDeviceButton->Location = System::Drawing::Point(12, 62);
			this->NewDeviceButton->Name = L"NewDeviceButton";
			this->NewDeviceButton->Size = System::Drawing::Size(134, 23);
			this->NewDeviceButton->TabIndex = 4;
			this->NewDeviceButton->Text = L"New Device";
			this->NewDeviceButton->UseVisualStyleBackColor = true;
			// 
			// DevicesLabel
			// 
			this->DevicesLabel->AutoSize = true;
			this->DevicesLabel->Location = System::Drawing::Point(152, 43);
			this->DevicesLabel->Name = L"DevicesLabel";
			this->DevicesLabel->Size = System::Drawing::Size(49, 13);
			this->DevicesLabel->TabIndex = 5;
			this->DevicesLabel->Text = L"Devices:";
			// 
			// EventLabel
			// 
			this->EventLabel->AutoSize = true;
			this->EventLabel->Location = System::Drawing::Point(306, 43);
			this->EventLabel->Name = L"EventLabel";
			this->EventLabel->Size = System::Drawing::Size(43, 13);
			this->EventLabel->TabIndex = 6;
			this->EventLabel->Text = L"Events:";
			// 
			// DeviceDataLabel
			// 
			this->DeviceDataLabel->AutoSize = true;
			this->DeviceDataLabel->Location = System::Drawing::Point(449, 62);
			this->DeviceDataLabel->Name = L"DeviceDataLabel";
			this->DeviceDataLabel->Size = System::Drawing::Size(70, 13);
			this->DeviceDataLabel->TabIndex = 7;
			this->DeviceDataLabel->Text = L"Device Data:";
			// 
			// DeviceIDTextBox
			// 
			this->DeviceIDTextBox->Location = System::Drawing::Point(494, 83);
			this->DeviceIDTextBox->Name = L"DeviceIDTextBox";
			this->DeviceIDTextBox->Size = System::Drawing::Size(109, 20);
			this->DeviceIDTextBox->TabIndex = 8;
			// 
			// DeviceIDLabel
			// 
			this->DeviceIDLabel->AutoSize = true;
			this->DeviceIDLabel->Location = System::Drawing::Point(449, 86);
			this->DeviceIDLabel->Name = L"DeviceIDLabel";
			this->DeviceIDLabel->Size = System::Drawing::Size(21, 13);
			this->DeviceIDLabel->TabIndex = 9;
			this->DeviceIDLabel->Text = L"ID:";
			// 
			// EventDataLabel
			// 
			this->EventDataLabel->AutoSize = true;
			this->EventDataLabel->Location = System::Drawing::Point(449, 119);
			this->EventDataLabel->Name = L"EventDataLabel";
			this->EventDataLabel->Size = System::Drawing::Size(64, 13);
			this->EventDataLabel->TabIndex = 10;
			this->EventDataLabel->Text = L"Event Data:";
			// 
			// EventTypeLabel
			// 
			this->EventTypeLabel->AutoSize = true;
			this->EventTypeLabel->Location = System::Drawing::Point(449, 145);
			this->EventTypeLabel->Name = L"EventTypeLabel";
			this->EventTypeLabel->Size = System::Drawing::Size(34, 13);
			this->EventTypeLabel->TabIndex = 11;
			this->EventTypeLabel->Text = L"Type:";
			// 
			// EventHourLabel
			// 
			this->EventHourLabel->AutoSize = true;
			this->EventHourLabel->Location = System::Drawing::Point(449, 173);
			this->EventHourLabel->Name = L"EventHourLabel";
			this->EventHourLabel->Size = System::Drawing::Size(33, 13);
			this->EventHourLabel->TabIndex = 12;
			this->EventHourLabel->Text = L"Hour:";
			// 
			// EventMinuteLabel
			// 
			this->EventMinuteLabel->AutoSize = true;
			this->EventMinuteLabel->Location = System::Drawing::Point(449, 201);
			this->EventMinuteLabel->Name = L"EventMinuteLabel";
			this->EventMinuteLabel->Size = System::Drawing::Size(42, 13);
			this->EventMinuteLabel->TabIndex = 13;
			this->EventMinuteLabel->Text = L"Minute:";
			// 
			// EventTypeComboBox
			// 
			this->EventTypeComboBox->FormattingEnabled = true;
			this->EventTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"On", L"Off"});
			this->EventTypeComboBox->Location = System::Drawing::Point(494, 142);
			this->EventTypeComboBox->Name = L"EventTypeComboBox";
			this->EventTypeComboBox->Size = System::Drawing::Size(109, 21);
			this->EventTypeComboBox->TabIndex = 14;
			this->EventTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(24) {L"00", L"01", L"02", L"03", L"04", L"05", L"06", 
				L"07", L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"});
			this->comboBox2->Location = System::Drawing::Point(494, 170);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(109, 21);
			this->comboBox2->TabIndex = 15;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"00", L"15", L"30", L"45"});
			this->comboBox3->Location = System::Drawing::Point(494, 198);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(109, 21);
			this->comboBox3->TabIndex = 16;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(658, 362);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->EventTypeComboBox);
			this->Controls->Add(this->EventMinuteLabel);
			this->Controls->Add(this->EventHourLabel);
			this->Controls->Add(this->EventTypeLabel);
			this->Controls->Add(this->EventDataLabel);
			this->Controls->Add(this->DeviceIDLabel);
			this->Controls->Add(this->DeviceIDTextBox);
			this->Controls->Add(this->DeviceDataLabel);
			this->Controls->Add(this->EventLabel);
			this->Controls->Add(this->DevicesLabel);
			this->Controls->Add(this->NewDeviceButton);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->EventsListBox);
			this->Controls->Add(this->DevicesListBox);
			this->Controls->Add(this->TopMenu);
			this->MainMenuStrip = this->TopMenu;
			this->Name = L"MainWindow";
			this->Text = L"HomeSecurity";
			this->TopMenu->ResumeLayout(false);
			this->TopMenu->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripStatusLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {

			OpenFileDialog ^ dialog = gcnew OpenFileDialog();
			dialog->DefaultExt = L"xml";
			dialog->Filter = L"Configuration File (*.xml)|*.xml|All files (*.*)|*.*";
			dialog->AddExtension = true;

			if(dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//if(!loadConf(_T(conf_file)))
			}

		 }
private: System::Void DevicesListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

