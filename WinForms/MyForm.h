#pragma once

#include "Parser.h"
#include "Function_analisys.h"
#include "Segment_analisys.h"
#include "Builder.h"

namespace WinForms {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктораs
            //
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::ToolStripMenuItem^ управлениеToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ помощьToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ очToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ выполнитьToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ завершитьToolStripMenuItem;
    private: System::Windows::Forms::TextBox^ textBox8;
    private: System::Windows::Forms::TextBox^ textBox7;
    private: System::Windows::Forms::TextBox^ textBox6;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::ListBox^ listBox3;
    private: System::Windows::Forms::ListBox^ listBox4;
    private: System::Windows::Forms::ListBox^ listBox2;
    private: System::Windows::Forms::ListBox^ listBox1;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::TextBox^ textBox12;
    private: System::Windows::Forms::TextBox^ textBox11;
    private: System::Windows::Forms::TextBox^ textBox10;
    private: System::Windows::Forms::TextBox^ textBox9;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::ListBox^ listBox5;
    private: System::Windows::Forms::ListBox^ listBox6;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::Label^ label15;
    private: System::Windows::Forms::Label^ label16;
    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::Label^ label19;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::Label^ label20;
    private: System::Windows::Forms::CheckBox^ checkBox1;

           /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           /// <summary>
           /// Требуемый метод для поддержки конструктора — не изменяйте 
           /// содержимое этого метода с помощью редактора кода.
           /// </summary>
           void InitializeComponent(void)
           {
               System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
               System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
               System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
               System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
               System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->управлениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->помощьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->очToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->выполнитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->завершитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->textBox8 = (gcnew System::Windows::Forms::TextBox());
               this->textBox7 = (gcnew System::Windows::Forms::TextBox());
               this->textBox6 = (gcnew System::Windows::Forms::TextBox());
               this->textBox5 = (gcnew System::Windows::Forms::TextBox());
               this->label9 = (gcnew System::Windows::Forms::Label());
               this->label10 = (gcnew System::Windows::Forms::Label());
               this->label11 = (gcnew System::Windows::Forms::Label());
               this->label12 = (gcnew System::Windows::Forms::Label());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->listBox3 = (gcnew System::Windows::Forms::ListBox());
               this->listBox4 = (gcnew System::Windows::Forms::ListBox());
               this->listBox2 = (gcnew System::Windows::Forms::ListBox());
               this->listBox1 = (gcnew System::Windows::Forms::ListBox());
               this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->textBox4 = (gcnew System::Windows::Forms::TextBox());
               this->textBox3 = (gcnew System::Windows::Forms::TextBox());
               this->textBox2 = (gcnew System::Windows::Forms::TextBox());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->textBox12 = (gcnew System::Windows::Forms::TextBox());
               this->textBox11 = (gcnew System::Windows::Forms::TextBox());
               this->textBox10 = (gcnew System::Windows::Forms::TextBox());
               this->textBox9 = (gcnew System::Windows::Forms::TextBox());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label13 = (gcnew System::Windows::Forms::Label());
               this->listBox5 = (gcnew System::Windows::Forms::ListBox());
               this->listBox6 = (gcnew System::Windows::Forms::ListBox());
               this->label14 = (gcnew System::Windows::Forms::Label());
               this->label15 = (gcnew System::Windows::Forms::Label());
               this->label16 = (gcnew System::Windows::Forms::Label());
               this->label17 = (gcnew System::Windows::Forms::Label());
               this->label18 = (gcnew System::Windows::Forms::Label());
               this->label19 = (gcnew System::Windows::Forms::Label());
               this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
               this->label20 = (gcnew System::Windows::Forms::Label());
               this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
               this->menuStrip1->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
               this->SuspendLayout();
               // 
               // menuStrip1
               // 
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                   this->управлениеToolStripMenuItem,
                       this->завершитьToolStripMenuItem
               });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(931, 24);
               this->menuStrip1->TabIndex = 16;
               this->menuStrip1->Text = L"menuStrip1";
               // 
               // управлениеToolStripMenuItem
               // 
               this->управлениеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                   this->помощьToolStripMenuItem,
                       this->очToolStripMenuItem, this->выполнитьToolStripMenuItem
               });
               this->управлениеToolStripMenuItem->Name = L"управлениеToolStripMenuItem";
               this->управлениеToolStripMenuItem->Size = System::Drawing::Size(85, 20);
               this->управлениеToolStripMenuItem->Text = L"Управление";
               // 
               // помощьToolStripMenuItem
               // 
               this->помощьToolStripMenuItem->Name = L"помощьToolStripMenuItem";
               this->помощьToolStripMenuItem->Size = System::Drawing::Size(136, 22);
               this->помощьToolStripMenuItem->Text = L"Помощь";
               this->помощьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::помощьToolStripMenuItem_Click);
               // 
               // очToolStripMenuItem
               // 
               this->очToolStripMenuItem->Name = L"очToolStripMenuItem";
               this->очToolStripMenuItem->Size = System::Drawing::Size(136, 22);
               this->очToolStripMenuItem->Text = L"Очистить";
               this->очToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::очиститьToolStripMenuItem_Click);
               // 
               // выполнитьToolStripMenuItem
               // 
               this->выполнитьToolStripMenuItem->Name = L"выполнитьToolStripMenuItem";
               this->выполнитьToolStripMenuItem->Size = System::Drawing::Size(136, 22);
               this->выполнитьToolStripMenuItem->Text = L"Выполнить";
               this->выполнитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выполнитьToolStripMenuItem_Click);
               // 
               // завершитьToolStripMenuItem
               // 
               this->завершитьToolStripMenuItem->Name = L"завершитьToolStripMenuItem";
               this->завершитьToolStripMenuItem->Size = System::Drawing::Size(80, 20);
               this->завершитьToolStripMenuItem->Text = L"Завершить";
               this->завершитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::завершитьToolStripMenuItem_Click);
               // 
               // textBox8
               // 
               this->textBox8->Location = System::Drawing::Point(431, 497);
               this->textBox8->Name = L"textBox8";
               this->textBox8->Size = System::Drawing::Size(112, 20);
               this->textBox8->TabIndex = 86;
               // 
               // textBox7
               // 
               this->textBox7->Location = System::Drawing::Point(431, 471);
               this->textBox7->Name = L"textBox7";
               this->textBox7->Size = System::Drawing::Size(112, 20);
               this->textBox7->TabIndex = 85;
               // 
               // textBox6
               // 
               this->textBox6->Location = System::Drawing::Point(431, 445);
               this->textBox6->Name = L"textBox6";
               this->textBox6->Size = System::Drawing::Size(112, 20);
               this->textBox6->TabIndex = 84;
               // 
               // textBox5
               // 
               this->textBox5->Location = System::Drawing::Point(431, 419);
               this->textBox5->Name = L"textBox5";
               this->textBox5->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
               this->textBox5->Size = System::Drawing::Size(182, 20);
               this->textBox5->TabIndex = 83;
               // 
               // label9
               // 
               this->label9->AutoSize = true;
               this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label9->Location = System::Drawing::Point(318, 497);
               this->label9->Name = L"label9";
               this->label9->Size = System::Drawing::Size(33, 16);
               this->label9->TabIndex = 82;
               this->label9->Text = L"Шаг";
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label10->Location = System::Drawing::Point(318, 472);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(105, 16);
               this->label10->TabIndex = 81;
               this->label10->Text = L"Конец отрезка";
               // 
               // label11
               // 
               this->label11->AutoSize = true;
               this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label11->Location = System::Drawing::Point(318, 449);
               this->label11->Name = L"label11";
               this->label11->Size = System::Drawing::Size(115, 16);
               this->label11->TabIndex = 80;
               this->label11->Text = L"Начало отрезка";
               // 
               // label12
               // 
               this->label12->AutoSize = true;
               this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label12->Location = System::Drawing::Point(318, 423);
               this->label12->Name = L"label12";
               this->label12->Size = System::Drawing::Size(83, 16);
               this->label12->TabIndex = 79;
               this->label12->Text = L"Функция (2)";
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label8->Location = System::Drawing::Point(0, 497);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(33, 16);
               this->label8->TabIndex = 78;
               this->label8->Text = L"Шаг";
               // 
               // listBox3
               // 
               this->listBox3->FormattingEnabled = true;
               this->listBox3->Location = System::Drawing::Point(621, 49);
               this->listBox3->Name = L"listBox3";
               this->listBox3->Size = System::Drawing::Size(64, 329);
               this->listBox3->TabIndex = 77;
               // 
               // listBox4
               // 
               this->listBox4->FormattingEnabled = true;
               this->listBox4->Location = System::Drawing::Point(691, 49);
               this->listBox4->Name = L"listBox4";
               this->listBox4->Size = System::Drawing::Size(64, 329);
               this->listBox4->TabIndex = 76;
               // 
               // listBox2
               // 
               this->listBox2->FormattingEnabled = true;
               this->listBox2->Location = System::Drawing::Point(549, 49);
               this->listBox2->Name = L"listBox2";
               this->listBox2->Size = System::Drawing::Size(64, 329);
               this->listBox2->TabIndex = 75;
               // 
               // listBox1
               // 
               this->listBox1->FormattingEnabled = true;
               this->listBox1->Location = System::Drawing::Point(479, 49);
               this->listBox1->Name = L"listBox1";
               this->listBox1->Size = System::Drawing::Size(64, 329);
               this->listBox1->TabIndex = 74;
               // 
               // chart1
               // 
               this->chart1->BackColor = System::Drawing::SystemColors::ScrollBar;
               chartArea1->Name = L"Ch1";
               this->chart1->ChartAreas->Add(chartArea1);
               legend1->Name = L"Legend1";
               this->chart1->Legends->Add(legend1);
               this->chart1->Location = System::Drawing::Point(12, 27);
               this->chart1->Name = L"chart1";
               series1->BorderWidth = 2;
               series1->ChartArea = L"Ch1";
               series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
               series1->Color = System::Drawing::Color::Blue;
               series1->Legend = L"Legend1";
               series1->Name = L"Function(1)";
               series2->BorderWidth = 2;
               series2->ChartArea = L"Ch1";
               series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
               series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               series2->Legend = L"Legend1";
               series2->Name = L"Function(2)";
               series3->BorderWidth = 2;
               series3->ChartArea = L"Ch1";
               series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
               series3->Color = System::Drawing::Color::Red;
               series3->Legend = L"Legend1";
               series3->Name = L"Function(3)";
               this->chart1->Series->Add(series1);
               this->chart1->Series->Add(series2);
               this->chart1->Series->Add(series3);
               this->chart1->Size = System::Drawing::Size(458, 367);
               this->chart1->TabIndex = 73;
               this->chart1->Text = L"chart1";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label3->Location = System::Drawing::Point(0, 472);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(105, 16);
               this->label3->TabIndex = 72;
               this->label3->Text = L"Конец отрезка";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label2->Location = System::Drawing::Point(0, 449);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(115, 16);
               this->label2->TabIndex = 71;
               this->label2->Text = L"Начало отрезка";
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label1->Location = System::Drawing::Point(0, 423);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(83, 16);
               this->label1->TabIndex = 70;
               this->label1->Text = L"Функция (1)";
               // 
               // textBox4
               // 
               this->textBox4->Location = System::Drawing::Point(121, 497);
               this->textBox4->Name = L"textBox4";
               this->textBox4->Size = System::Drawing::Size(112, 20);
               this->textBox4->TabIndex = 69;
               // 
               // textBox3
               // 
               this->textBox3->Location = System::Drawing::Point(121, 471);
               this->textBox3->Name = L"textBox3";
               this->textBox3->Size = System::Drawing::Size(112, 20);
               this->textBox3->TabIndex = 68;
               // 
               // textBox2
               // 
               this->textBox2->Location = System::Drawing::Point(121, 445);
               this->textBox2->Name = L"textBox2";
               this->textBox2->Size = System::Drawing::Size(112, 20);
               this->textBox2->TabIndex = 67;
               // 
               // textBox1
               // 
               this->textBox1->Location = System::Drawing::Point(121, 419);
               this->textBox1->Name = L"textBox1";
               this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
               this->textBox1->Size = System::Drawing::Size(182, 20);
               this->textBox1->TabIndex = 66;
               // 
               // comboBox1
               // 
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1 функция", L"2 функции", L"3 функции " });
               this->comboBox1->Location = System::Drawing::Point(598, 390);
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(84, 21);
               this->comboBox1->TabIndex = 90;
               this->comboBox1->Text = L"Не указано";
               this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
               // 
               // textBox12
               // 
               this->textBox12->Location = System::Drawing::Point(737, 497);
               this->textBox12->Name = L"textBox12";
               this->textBox12->Size = System::Drawing::Size(112, 20);
               this->textBox12->TabIndex = 98;
               // 
               // textBox11
               // 
               this->textBox11->Location = System::Drawing::Point(737, 471);
               this->textBox11->Name = L"textBox11";
               this->textBox11->Size = System::Drawing::Size(112, 20);
               this->textBox11->TabIndex = 97;
               // 
               // textBox10
               // 
               this->textBox10->Location = System::Drawing::Point(737, 445);
               this->textBox10->Name = L"textBox10";
               this->textBox10->Size = System::Drawing::Size(112, 20);
               this->textBox10->TabIndex = 96;
               // 
               // textBox9
               // 
               this->textBox9->Location = System::Drawing::Point(737, 419);
               this->textBox9->Name = L"textBox9";
               this->textBox9->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
               this->textBox9->Size = System::Drawing::Size(182, 20);
               this->textBox9->TabIndex = 95;
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label4->Location = System::Drawing::Point(624, 497);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(33, 16);
               this->label4->TabIndex = 94;
               this->label4->Text = L"Шаг";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label5->Location = System::Drawing::Point(624, 472);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(105, 16);
               this->label5->TabIndex = 93;
               this->label5->Text = L"Конец отрезка";
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label6->Location = System::Drawing::Point(624, 449);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(115, 16);
               this->label6->TabIndex = 92;
               this->label6->Text = L"Начало отрезка";
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label7->Location = System::Drawing::Point(624, 423);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(83, 16);
               this->label7->TabIndex = 91;
               this->label7->Text = L"Функция (3)";
               // 
               // label13
               // 
               this->label13->AutoSize = true;
               this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label13->Location = System::Drawing::Point(476, 391);
               this->label13->Name = L"label13";
               this->label13->Size = System::Drawing::Size(116, 16);
               this->label13->TabIndex = 99;
               this->label13->Text = L"Кол-во функций:";
               // 
               // listBox5
               // 
               this->listBox5->FormattingEnabled = true;
               this->listBox5->Location = System::Drawing::Point(761, 49);
               this->listBox5->Name = L"listBox5";
               this->listBox5->Size = System::Drawing::Size(64, 329);
               this->listBox5->TabIndex = 100;
               // 
               // listBox6
               // 
               this->listBox6->FormattingEnabled = true;
               this->listBox6->Location = System::Drawing::Point(831, 49);
               this->listBox6->Name = L"listBox6";
               this->listBox6->Size = System::Drawing::Size(64, 329);
               this->listBox6->TabIndex = 101;
               // 
               // label14
               // 
               this->label14->AutoSize = true;
               this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label14->Location = System::Drawing::Point(492, 30);
               this->label14->Name = L"label14";
               this->label14->Size = System::Drawing::Size(34, 16);
               this->label14->TabIndex = 102;
               this->label14->Text = L"X(1):";
               // 
               // label15
               // 
               this->label15->AutoSize = true;
               this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label15->Location = System::Drawing::Point(562, 30);
               this->label15->Name = L"label15";
               this->label15->Size = System::Drawing::Size(35, 16);
               this->label15->TabIndex = 103;
               this->label15->Text = L"Y(1):";
               // 
               // label16
               // 
               this->label16->AutoSize = true;
               this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label16->Location = System::Drawing::Point(705, 30);
               this->label16->Name = L"label16";
               this->label16->Size = System::Drawing::Size(35, 16);
               this->label16->TabIndex = 105;
               this->label16->Text = L"Y(2):";
               // 
               // label17
               // 
               this->label17->AutoSize = true;
               this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label17->Location = System::Drawing::Point(635, 30);
               this->label17->Name = L"label17";
               this->label17->Size = System::Drawing::Size(34, 16);
               this->label17->TabIndex = 104;
               this->label17->Text = L"X(2):";
               // 
               // label18
               // 
               this->label18->AutoSize = true;
               this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label18->Location = System::Drawing::Point(848, 30);
               this->label18->Name = L"label18";
               this->label18->Size = System::Drawing::Size(35, 16);
               this->label18->TabIndex = 107;
               this->label18->Text = L"Y(3):";
               // 
               // label19
               // 
               this->label19->AutoSize = true;
               this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label19->Location = System::Drawing::Point(778, 30);
               this->label19->Name = L"label19";
               this->label19->Size = System::Drawing::Size(34, 16);
               this->label19->TabIndex = 106;
               this->label19->Text = L"X(3):";
               // 
               // comboBox2
               // 
               this->comboBox2->DisplayMember = L"asd";
               this->comboBox2->FormattingEnabled = true;
               this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Выключить", L"По оси Х", L"По оси У", L"По обоим осям" });
               this->comboBox2->Location = System::Drawing::Point(749, 390);
               this->comboBox2->Name = L"comboBox2";
               this->comboBox2->Size = System::Drawing::Size(100, 21);
               this->comboBox2->TabIndex = 108;
               this->comboBox2->Text = L"Не указано";
               this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
               // 
               // label20
               // 
               this->label20->AutoSize = true;
               this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label20->Location = System::Drawing::Point(688, 391);
               this->label20->Name = L"label20";
               this->label20->Size = System::Drawing::Size(55, 16);
               this->label20->TabIndex = 109;
               this->label20->Text = L"Курсор";
               // 
               // checkBox1
               // 
               this->checkBox1->AutoSize = true;
               this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->checkBox1->Location = System::Drawing::Point(857, 391);
               this->checkBox1->Name = L"checkBox1";
               this->checkBox1->Size = System::Drawing::Size(62, 20);
               this->checkBox1->TabIndex = 110;
               this->checkBox1->Text = L"Zoom";
               this->checkBox1->UseVisualStyleBackColor = true;
               this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::SystemColors::InactiveCaption;
               this->ClientSize = System::Drawing::Size(931, 532);
               this->ControlBox = false;
               this->Controls->Add(this->checkBox1);
               this->Controls->Add(this->label20);
               this->Controls->Add(this->comboBox2);
               this->Controls->Add(this->label18);
               this->Controls->Add(this->label19);
               this->Controls->Add(this->label16);
               this->Controls->Add(this->label17);
               this->Controls->Add(this->label15);
               this->Controls->Add(this->label14);
               this->Controls->Add(this->listBox6);
               this->Controls->Add(this->listBox5);
               this->Controls->Add(this->label13);
               this->Controls->Add(this->textBox12);
               this->Controls->Add(this->textBox11);
               this->Controls->Add(this->textBox10);
               this->Controls->Add(this->textBox9);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->label5);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->label7);
               this->Controls->Add(this->comboBox1);
               this->Controls->Add(this->textBox8);
               this->Controls->Add(this->textBox7);
               this->Controls->Add(this->textBox6);
               this->Controls->Add(this->textBox5);
               this->Controls->Add(this->label9);
               this->Controls->Add(this->label10);
               this->Controls->Add(this->label11);
               this->Controls->Add(this->label12);
               this->Controls->Add(this->label8);
               this->Controls->Add(this->listBox3);
               this->Controls->Add(this->listBox4);
               this->Controls->Add(this->listBox2);
               this->Controls->Add(this->listBox1);
               this->Controls->Add(this->chart1);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->textBox4);
               this->Controls->Add(this->textBox3);
               this->Controls->Add(this->textBox2);
               this->Controls->Add(this->textBox1);
               this->Controls->Add(this->menuStrip1);
               this->MainMenuStrip = this->menuStrip1;
               this->MaximizeBox = false;
               this->MinimizeBox = false;
               this->Name = L"MyForm";
               this->ShowIcon = false;
               this->Text = L"Function builder";
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

           void activefunction() // включает использующиеся элементы ввода-вывода
           {
               textBox5->Enabled = true; textBox6->Enabled = true; textBox7->Enabled = true; textBox8->Enabled = true;
               textBox9->Enabled = true; textBox10->Enabled = true; textBox11->Enabled = true; textBox12->Enabled = true;
               listBox3->Enabled = true; listBox4->Enabled = true;
               listBox3->BackColor = Color::White; listBox4->BackColor = Color::White;
               listBox5->Enabled = true; listBox6->Enabled = true;
               listBox5->BackColor = Color::White; listBox6->BackColor = Color::White;
           }
           void deactivefunction() // выключает неиспользующиеся элементы ввода-вывода
           {
               if (comboBox1->SelectedIndex == 0)
               {
                   textBox5->Enabled = false; textBox6->Enabled = false; textBox7->Enabled = false; textBox8->Enabled = false;
                   textBox9->Enabled = false; textBox10->Enabled = false; textBox11->Enabled = false; textBox12->Enabled = false;
                   listBox3->Enabled = false; listBox4->Enabled = false;
                   listBox5->Enabled = false; listBox6->Enabled = false;
                   listBox3->BackColor = Color::LightGray; listBox4->BackColor = Color::LightGray;
                   listBox5->BackColor = Color::LightGray; listBox6->BackColor = Color::LightGray;
               }
               else if (comboBox1->SelectedIndex == 1)
               {
                   textBox9->Enabled = false; textBox10->Enabled = false; textBox11->Enabled = false; textBox12->Enabled = false;
                   listBox5->Enabled = false; listBox6->Enabled = false;
                   listBox5->BackColor = Color::LightGray;
                   listBox6->BackColor = Color::LightGray;
               }
           }

           void use_cursor() { // включение-выключение курсора
               chart1->ChartAreas["Ch1"]->CursorX->Interval = 0.1; // интервал курсора по х
               chart1->ChartAreas["Ch1"]->CursorY->Interval = 0.1; // интервал курсора по у
               chart1->ChartAreas["Ch1"]->CursorX->LineColor = Color::DeepPink; // цвет курсора по Х
               chart1->ChartAreas["Ch1"]->CursorY->LineColor = Color::DeepPink; // цвет курсора по У

               if (comboBox2->SelectedIndex == 0) { // выключение курсора
                   chart1->ChartAreas["Ch1"]->CursorX->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorY->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorX->LineColor = Color::Transparent; // если курсор уже был использован, то отключить
                   chart1->ChartAreas["Ch1"]->CursorY->LineColor = Color::Transparent; // если курсор уже был использован, то отключить
               }
               else if (comboBox2->SelectedIndex == 1) { // включение курсора по оси x   
                   chart1->ChartAreas["Ch1"]->CursorY->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorY->LineColor = Color::Transparent; // если курсор уже был использован, то отключить
                   chart1->ChartAreas["Ch1"]->CursorX->IsUserEnabled = true;
               }
               else if (comboBox2->SelectedIndex == 2) { // включение курсора по оси y
                   chart1->ChartAreas["Ch1"]->CursorX->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorX->LineColor = Color::Transparent; // если курсор уже был использован, то отключить
                   chart1->ChartAreas["Ch1"]->CursorY->IsUserEnabled = true;
               }
               else if (comboBox2->SelectedIndex == 3) { // включение курсора по осям х и y
                   chart1->ChartAreas["Ch1"]->CursorX->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorY->IsUserEnabled = false;
                   chart1->ChartAreas["Ch1"]->CursorX->IsUserEnabled = true;
                   chart1->ChartAreas["Ch1"]->CursorY->IsUserEnabled = true;
               }
           }

#pragma endregion

    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        activefunction(); // включает использующиеся элементы ввода-вывода
        deactivefunction(); // выключает неиспользующиеся элементы ввода-вывода
    }

    private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        use_cursor(); // включение-выключение курсора
    }

    private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { // включение увеличения (zoom'а)
        if (checkBox1->Checked)
            chart1->ChartAreas["Ch1"]->CursorX->IsUserSelectionEnabled = true; // включить увеличение
        else
            chart1->ChartAreas["Ch1"]->CursorX->IsUserSelectionEnabled = false; // выключить увеличение
    }

    private: System::Void выполнитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

        //Функция (1):
        if (comboBox1->SelectedIndex == 0 || comboBox1->SelectedIndex == 1 || comboBox1->SelectedIndex == 2)
        {
            const int number_func1 = 1; // Номер функции
            String^ function1 = textBox1->Text; // Функция 
            String^ some_start_digit1 = textBox2->Text; // начало интервала 
            String^ some_end_digit1 = textBox3->Text; // конец интервала
            String^ some_step1 = textBox4->Text; // указанный шаг 

            Builder First_Function(function1, number_func1); // создание объекта строителя для первой функции

            if (First_Function.test_function(function1)) // проверяется корректно ли введена функция
                goto link; // в случае, если введена некорректна

            if (First_Function.test_segment(some_start_digit1, some_end_digit1, some_step1)) // проверется корректно ли введены доп. условия
                goto link; // в случае, если введена некорректна

            std::vector<std::vector<double>> itog = First_Function.result(); // получаем результат в виде двух векторов со значениями Х и У
            chart1->Series["Function(1)"]->Points->Clear(); // Очистка графика 1

            for (size_t i = 0, j = 0; i < itog[0].size(), j < itog[1].size(); i++, j++)
            {
                listBox1->Items->Add(Math::Round(itog[0][i], 7)); // выводим точку
                listBox2->Items->Add(Math::Round(itog[1][j], 7)); // выводим значение функции в точке

                chart1->Series["Function(1)"]->Points->AddXY(itog[0][i], itog[1][j]); // Строим график 1
            }
        }
        else
        {
            MessageBox::Show("Пожалуйста, уточните количество используемых функций", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        link: // В разных ситуациях приходится выходить из события, чтобы сто раз не писать сделал через ссылку на место выхода
            return; // выход из события
        }

        //Функция (2):
        if (comboBox1->SelectedIndex == 1 || comboBox1->SelectedIndex == 2)
        {
            const int number_func2 = 2; // Номер функции
            String^ function2 = textBox5->Text; // Функция 
            String^ some_start_digit2 = textBox6->Text; // начало интервала
            String^ some_end_digit2 = textBox7->Text; // конец интервала
            String^ some_step2 = textBox8->Text; // указанный шаг 

            Builder Second_Function(function2, number_func2); // создание объекта строителя для второй функции

            if (Second_Function.test_function(function2)) //проверяется корректно ли введена функция
                goto link; // в случае, если введена некорректна

            if (Second_Function.test_segment(some_start_digit2, some_end_digit2, some_step2)) //проверется корректно ли введены доп. условия
                goto link; // в случае, если введена некорректна

            std::vector<std::vector<double>> itog = Second_Function.result(); // получаем результат в виде двух векторов со значениями Х и У
            chart1->Series["Function(2)"]->Points->Clear(); // Очистка графика 2

            for (size_t i = 0, j = 0; i < itog[0].size(), j < itog[1].size(); i++, j++)
            {
                listBox3->Items->Add(Math::Round(itog[0][i], 7)); // выводим точку
                listBox4->Items->Add(Math::Round(itog[1][j], 7)); // выводим значение функции в точке

                chart1->Series["Function(2)"]->Points->AddXY(itog[0][i], itog[1][j]); // Строим график 2
            }
        }

        //Функция (3):
        if (comboBox1->SelectedIndex == 2)
        {
            const int number_func3 = 3; // Номер функции
            String^ function3 = textBox9->Text; // Функция 
            String^ some_start_digit3 = textBox10->Text; // начало интервала
            String^ some_end_digit3 = textBox11->Text; // конец интервала
            String^ some_step3 = textBox12->Text; // указанный шаг 

            Builder Third_Function(function3, number_func3); // создание объекта строителя для второй функции

            if (Third_Function.test_function(function3)) //проверяется корректно ли введена функция
                goto link; // в случае, если введена некорректна

            if (Third_Function.test_segment(some_start_digit3, some_end_digit3, some_step3)) //проверется корректно ли введены доп. условия
                goto link; // в случае, если введена некорректна

            std::vector<std::vector<double>> itog = Third_Function.result(); // получаем результат в виде двух векторов со значениями Х и У
            chart1->Series["Function(3)"]->Points->Clear(); // Очистка графика 3

            for (size_t i = 0, j = 0; i < itog[0].size(), j < itog[1].size(); i++, j++)
            {
                listBox5->Items->Add(Math::Round(itog[0][i], 7)); // выводим точку
                listBox6->Items->Add(Math::Round(itog[1][j], 7)); // выводим значение функции в точке

                chart1->Series["Function(3)"]->Points->AddXY(itog[0][i], itog[1][j]); // Строим график 3
            }
        }
    }

    private: System::Void помощьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Информация
        MessageBox::Show
        ("1. Перед работой предварительно выбрать кол-во функций для использования.\n" +
            "2. Записывать функции(1), (2), (3) соответственно через \"x\",\"y\",\"z\".\n" +
            "3. Пример ввода в функцию (1):  x^2-3*sin(x+15)+9.\n" +
            "4. Доступные тригометрические функции sin, cos, tan, cot, asin, acos, atan, acot.\n" +
            "5. Функции, имеющие разрыв строиться не будут. Появившийся красный крест исчезнет при перезапуске.\n" +
            "6. Для включение курсора выбрать нужные оси.\n" +
            "7. При надобности есть возможность увеличения графика, после активации \"Zoom\". Для максимального увеличения подключить курсор.\n",
            "Информация по использованию",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Очистка всего
        textBox1->Text = "";  textBox2->Text = "";  textBox3->Text = "";  textBox4->Text = ""; // очистка текстбоксов
        textBox5->Text = "";  textBox6->Text = "";  textBox7->Text = "";  textBox8->Text = ""; // очистка текстбоксов
        textBox9->Text = "";  textBox10->Text = ""; textBox11->Text = ""; textBox12->Text = ""; // очистка текстбоксов

        listBox1->Items->Clear(); listBox2->Items->Clear(); // очистка листбоксов
        listBox3->Items->Clear(); listBox4->Items->Clear(); // очистка листбоксов
        listBox5->Items->Clear(); listBox6->Items->Clear(); // очистка листбоксов

        chart1->Series["Function(1)"]->Points->Clear(); // Очистка графика 
        chart1->Series["Function(2)"]->Points->Clear(); // Очистка графика 
        chart1->Series["Function(3)"]->Points->Clear(); // Очистка графика 
        chart1->Refresh(); // Обновление графика. (Необязательно)


        comboBox1->SelectedIndex = -1; // Очистка комбобокса 
    }

    private: System::Void завершитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Выход
        this->Close();
    }
    };
}