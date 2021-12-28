#pragma once

#ifndef TINYEXPR_H
#define TINYEXPR_H


#ifdef __cplusplus
extern "C" {
#endif



	typedef struct te_expr {
		int type;
		union { double value; const double* bound; const void* function; };
		void* parameters[1];
	} te_expr;


	enum {
		TE_VARIABLE = 0,

		TE_FUNCTION0 = 8, TE_FUNCTION1, TE_FUNCTION2, TE_FUNCTION3,
		TE_FUNCTION4, TE_FUNCTION5, TE_FUNCTION6, TE_FUNCTION7,

		TE_CLOSURE0 = 16, TE_CLOSURE1, TE_CLOSURE2, TE_CLOSURE3,
		TE_CLOSURE4, TE_CLOSURE5, TE_CLOSURE6, TE_CLOSURE7,

		TE_FLAG_PURE = 32
	};

	typedef struct te_variable {
		const char* name;
		const void* address;
		int type;
		void* context;
	} te_variable;



	/* Parses the input expression, evaluates it, and frees it. */
	/* Returns NaN on error. */
	double te_interp(const char* expression, int* error);

	/* Parses the input expression and binds variables. */
	/* Returns NULL on error. */
	te_expr* te_compile(const char* expression, const te_variable* variables, int var_count, int* error);

	/* Evaluates the expression. */
	double te_eval(const te_expr* n);

	/* Prints debugging information on the syntax tree. */
	void te_print(const te_expr* n);

	/* Frees the expression. */
	/* This is safe to call on NULL pointers. */
	void te_free(te_expr* n);


#ifdef __cplusplus
}
#endif

#endif /*TINYEXPR_H*/

// Powyzszy kod jest skopiowany z pliku tinyexpr.h - https://github.com/codeplea/tinyexpr

#include <vcclr.h>
#include <msclr/marshal.h>
#include <stdio.h>

namespace Kalkulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o OknoKalkulatora
	/// </summary>
	public ref class OknoKalkulatora : public System::Windows::Forms::Form
	{
	public:
		OknoKalkulatora(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~OknoKalkulatora()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn7;
	protected:

	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn9;
	protected:



	private: System::Windows::Forms::Button^ backspace;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn0;
	private: System::Windows::Forms::Button^ btnDot;









	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::Button^ multiplication;


	private: System::Windows::Forms::Button^ division;
	private: System::Windows::Forms::Button^ additon;


	private: System::Windows::Forms::Button^ substraction;
	private: System::Windows::Forms::Button^ equal;



	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->backspace = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->multiplication = (gcnew System::Windows::Forms::Button());
			this->division = (gcnew System::Windows::Forms::Button());
			this->additon = (gcnew System::Windows::Forms::Button());
			this->substraction = (gcnew System::Windows::Forms::Button());
			this->equal = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn7
			// 
			this->btn7->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn7->Location = System::Drawing::Point(12, 191);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(85, 85);
			this->btn7->TabIndex = 0;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// textBox
			// 
			this->textBox->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox->ForeColor = System::Drawing::Color::White;
			this->textBox->Location = System::Drawing::Point(12, 12);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox->Size = System::Drawing::Size(360, 76);
			this->textBox->TabIndex = 1;
			this->textBox->Text = L"0";
			this->textBox->TextChanged += gcnew System::EventHandler(this, &OknoKalkulatora::textBox_TextChanged);
			// 
			// btn8
			// 
			this->btn8->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn8->Location = System::Drawing::Point(106, 191);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(85, 85);
			this->btn8->TabIndex = 0;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn9
			// 
			this->btn9->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn9->Location = System::Drawing::Point(197, 191);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(85, 85);
			this->btn9->TabIndex = 0;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// backspace
			// 
			this->backspace->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->backspace->Location = System::Drawing::Point(13, 100);
			this->backspace->Name = L"backspace";
			this->backspace->Size = System::Drawing::Size(85, 85);
			this->backspace->TabIndex = 0;
			this->backspace->Text = L"<-";
			this->backspace->UseVisualStyleBackColor = true;
			this->backspace->Click += gcnew System::EventHandler(this, &OknoKalkulatora::BackspaceClick);
			// 
			// btn4
			// 
			this->btn4->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn4->Location = System::Drawing::Point(13, 282);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(85, 85);
			this->btn4->TabIndex = 0;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn5
			// 
			this->btn5->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn5->Location = System::Drawing::Point(106, 282);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(85, 85);
			this->btn5->TabIndex = 0;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn6
			// 
			this->btn6->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn6->Location = System::Drawing::Point(197, 282);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(85, 85);
			this->btn6->TabIndex = 0;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn1
			// 
			this->btn1->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn1->Location = System::Drawing::Point(13, 373);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(85, 85);
			this->btn1->TabIndex = 0;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn2
			// 
			this->btn2->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn2->Location = System::Drawing::Point(106, 373);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(85, 85);
			this->btn2->TabIndex = 0;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn3
			// 
			this->btn3->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn3->Location = System::Drawing::Point(197, 373);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(85, 85);
			this->btn3->TabIndex = 0;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btn0
			// 
			this->btn0->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn0->Location = System::Drawing::Point(106, 464);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(85, 85);
			this->btn0->TabIndex = 0;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// btnDot
			// 
			this->btnDot->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDot->Location = System::Drawing::Point(12, 464);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(85, 85);
			this->btnDot->TabIndex = 0;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// clear
			// 
			this->clear->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->clear->Location = System::Drawing::Point(106, 100);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(176, 85);
			this->clear->TabIndex = 0;
			this->clear->Text = L"C";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &OknoKalkulatora::ClearTextBox);
			// 
			// multiplication
			// 
			this->multiplication->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->multiplication->Location = System::Drawing::Point(289, 191);
			this->multiplication->Name = L"multiplication";
			this->multiplication->Size = System::Drawing::Size(85, 85);
			this->multiplication->TabIndex = 0;
			this->multiplication->Text = L"*";
			this->multiplication->UseVisualStyleBackColor = true;
			this->multiplication->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// division
			// 
			this->division->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->division->Location = System::Drawing::Point(289, 100);
			this->division->Name = L"division";
			this->division->Size = System::Drawing::Size(85, 85);
			this->division->TabIndex = 0;
			this->division->Text = L"/";
			this->division->UseVisualStyleBackColor = true;
			this->division->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// additon
			// 
			this->additon->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->additon->Location = System::Drawing::Point(289, 373);
			this->additon->Name = L"additon";
			this->additon->Size = System::Drawing::Size(85, 85);
			this->additon->TabIndex = 0;
			this->additon->Text = L"+";
			this->additon->UseVisualStyleBackColor = true;
			this->additon->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// substraction
			// 
			this->substraction->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->substraction->Location = System::Drawing::Point(289, 282);
			this->substraction->Name = L"substraction";
			this->substraction->Size = System::Drawing::Size(85, 85);
			this->substraction->TabIndex = 0;
			this->substraction->Text = L"-";
			this->substraction->UseVisualStyleBackColor = true;
			this->substraction->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EnterNumber);
			// 
			// equal
			// 
			this->equal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->equal->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->equal->Location = System::Drawing::Point(197, 464);
			this->equal->Name = L"equal";
			this->equal->Size = System::Drawing::Size(177, 85);
			this->equal->TabIndex = 0;
			this->equal->Text = L"=";
			this->equal->UseVisualStyleBackColor = false;
			this->equal->Click += gcnew System::EventHandler(this, &OknoKalkulatora::EqualNumber);
			// 
			// OknoKalkulatora
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(384, 561);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->backspace);
			this->Controls->Add(this->substraction);
			this->Controls->Add(this->division);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->equal);
			this->Controls->Add(this->additon);
			this->Controls->Add(this->multiplication);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Name = L"OknoKalkulatora";
			this->Text = L"OknoKalkulatora";
			this->Load += gcnew System::EventHandler(this, &OknoKalkulatora::OknoKalkulatora_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ operation;

private: System::Void OknoKalkulatora_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EnterNumber(System::Object^ sender, System::EventArgs^ e) {
	Button^ Numbers = safe_cast<Button^>(sender);

	if (textBox->Text == "0") {
		textBox->Text = Numbers->Text;
	}
	else {
		textBox->Text = textBox->Text + Numbers->Text;
	}
}
private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void EqualNumber(System::Object^ sender, System::EventArgs^ e) {

	msclr::interop::marshal_context ctx;

	const char* converted = ctx.marshal_as<const char*>(textBox->Text);

	double answer = te_interp(converted, 0);

	textBox->Text = answer.ToString();
}
private: System::Void ClearTextBox(System::Object^ sender, System::EventArgs^ e) {
	textBox->Text = "0";
}
private: System::Void BackspaceClick(System::Object^ sender, System::EventArgs^ e) {
	if (textBox->Text->Length > 0) {
		textBox->Text = textBox->Text->Remove(textBox->Text->Length - 1, 1);
	}

	if (textBox->Text == "") {
		textBox->Text = "0";
	}
}
};
}
