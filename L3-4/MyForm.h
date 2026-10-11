#pragma once

namespace L34 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;




	protected:

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Точка", L"Лінія", L"Ламана", L"Многокутник", L"Прямокутник",
					L"Коло", L"Круг", L"Еліпс", L"Дуга", L"Крива", L"Трикутник", L"Будиночок"
			});
			this->listBox1->Location = System::Drawing::Point(303, 47);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(76, 160);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Червоний", L"Зелений", L"Синій", L"Жовтий", L"Чорний" });
			this->comboBox1->Location = System::Drawing::Point(97, 272);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 317);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"Лабараторна робота №3-4";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		graf->Clear(Color::White);

		Color selectedColor = Color::Black;

		if (comboBox1->SelectedItem != nullptr)
		{
			String^ colorName = comboBox1->SelectedItem->ToString();

			if (colorName == "Червоний") selectedColor = Color::Red;
			else if (colorName == "Зелений") selectedColor = Color::Green;
			else if (colorName == "Синій") selectedColor = Color::Blue;
			else if (colorName == "Жовтий") selectedColor = Color::Yellow;
			else if (colorName == "Чорний") selectedColor = Color::Black;
		}

		Pen^ dynamicPen = gcnew System::Drawing::Pen(selectedColor, 5);
		Pen^ dynamicPen8 = gcnew System::Drawing::Pen(selectedColor, 8);
		Brush^ dynamicBrush = gcnew System::Drawing::SolidBrush(selectedColor);

		switch (listBox1->SelectedIndex)
		{
		case 0: // Точка
			graf->FillRectangle(dynamicBrush, 150, 100, 4, 4);
			break;

		case 1: // Лінія 
			graf->DrawLine(dynamicPen8, 50, 50, 250, 150);
			break;

		case 2: // Ламана
		{
			cli::array<Point>^ linePoints = gcnew cli::array<Point>{
				Point(50, 150), Point(100, 50), Point(150, 150), Point(250, 50)
			};
			graf->DrawLines(dynamicPen, linePoints);
			break;
		}

		case 3: // Многокутник
		{
			cli::array<Point>^ polyPoints = gcnew cli::array<Point>{
				Point(150, 30), Point(220, 80), Point(190, 160), Point(110, 160), Point(80, 80)
			};
			graf->DrawPolygon(dynamicPen, polyPoints);
			break;
		}

		case 4: // Прямокутник
			graf->DrawRectangle(dynamicPen, 50, 50, 150, 100);
			break;

		case 5: // Коло
			graf->DrawEllipse(dynamicPen, 50, 40, 150, 150);
			break;

		case 6: // Круг
			graf->FillEllipse(dynamicBrush, 50, 40, 150, 150);
			break;

		case 7: // Еліпс
			graf->FillEllipse(dynamicBrush, 30, 60, 220, 100);
			break;

		case 8: // Дуга
			graf->DrawArc(dynamicPen, 50, 50, 150, 150, 180, 180);
			break;

		case 9: // Крива
		{
			cli::array<Point>^ curvePoints = gcnew cli::array<Point>{
				Point(50, 150), Point(100, 50), Point(150, 150), Point(200, 50), Point(250, 150)
			};
			graf->DrawCurve(dynamicPen, curvePoints);
			break;
		}

		case 10: // Трикутник
		{
			cli::array<Point>^ trianglePoints = gcnew cli::array<Point>{
				Point(150, 30), Point(250, 150), Point(50, 150)
			};
			graf->DrawPolygon(dynamicPen, trianglePoints);
			break;
		}

		case 11: // Будиночок
		{
			graf->DrawRectangle(dynamicPen, 100, 100, 150, 120);

			cli::array<Point>^ roofPoints = gcnew cli::array<Point>{
				Point(80, 100),
					Point(175, 40),
					Point(270, 100)
			};
			graf->DrawPolygon(dynamicPen, roofPoints);
			graf->DrawRectangle(dynamicPen, 155, 150, 40, 70);

			break;
		}
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listBox1->SelectedIndex != -1) {
			listBox1_SelectedIndexChanged(sender, e);
		}
	}
};
}
