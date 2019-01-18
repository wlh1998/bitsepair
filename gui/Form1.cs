using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 四则运算1
{
    public partial class Form1 : Form
    {
        private int seconds = 20,right=0,sum=0;
        string line_q,line_a;
        StreamReader sr = new StreamReader(@"qa.txt");
        public Form1()
        {
            InitializeComponent();
        }

        private void button_pause_Click(object sender, EventArgs e)
        {
            if(button_pause.Text=="暂停")
            {
                timer1.Stop();
                button_pause.Text = "继续";
                label_question.Text = "点击开始或继续按钮以继续";
            }
            else
            {
                timer1.Start();
                button_pause.Text = "暂停";
                label_question.Text = line_q;
            }
        }

        private void btn_start_Click(object sender, EventArgs e)
        {
            if (button_pause.Text == "暂停")

            {
                timer1.Start();
                if ((line_q = sr.ReadLine()) != null)
                {
                    label_question.Text = line_q;
                }
                else
                {
                    label_question.Text = "题库已空,棒棒！";
                    timer1.Stop();
                    seconds = 20;
                    label_time.Text = seconds.ToString();

                }
            }
            else
            {
                timer1.Start();
                button_pause.Text = "暂停";
                label_question.Text = line_q;
            }
            
        }
        private void button_confirm_Click(object sender, EventArgs e)
        {
            if(seconds==0||textBox_answer.Text!="")
            {
                if ((line_a = sr.ReadLine()) != null && textBox_answer.Text != line_a)
                {
                    if (textBox_answer.Text != "")
                    {
                        textBox.Text += "\r\n";
                        textBox.Text += line_q;
                        textBox.Text += "你的答案：";
                        textBox.Text += textBox_answer.Text;
                        textBox.Text += "  ";
                        textBox.Text += "正确答案：";
                        textBox.Text += line_a;
                    }
                    else
                    {
                        textBox.Text += "\r\n";
                        textBox.Text += line_q;
                        textBox.Text += "未在限时内作答";
                        textBox.Text += "  ";
                        textBox.Text += "正确答案：";
                        textBox.Text += line_a;
                    }

                }
                else
                {
                    right++;
                    label_right.Text = right.ToString();
                }
                if ((line_q = sr.ReadLine()) != null)
                {
                    label_question.Text = line_q;
                }
                else
                {
                    label_question.Text = "题库已空,棒棒！";
                    timer1.Stop();
                    seconds = 20;
                    label_time.Text = seconds.ToString();
                }
                seconds = 20;
                sum++;
                label_sum.Text = sum.ToString();
                textBox_answer.Text = null;
            }
            
            
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            seconds = (seconds == 0) ? 20 : seconds - 1;
            label_time.Text = seconds.ToString();
            if(label_time.Text=="0")
            {
                button_confirm_Click(null,null);
            }
        }
        
        
    }
}
