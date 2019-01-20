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
        private int seconds = 20,right=0,sum=0,flag=0;
        private static string CmdPath = @"C:\Windows\System32\cmd.exe";
        string output = "",cmd=@"calculator.exe -g 1000 qa.txt";
        string line_q,line_a;
        StreamReader sr;
        public Form1()
        {
            InitializeComponent();
        }
        public static void RunCmd(string cmd, out string output)//命令行调用函数
        {
            cmd = cmd.Trim().TrimEnd('&') + "&exit";//说明：不管命令是否成功均执行exit命令，否则当调用ReadToEnd()方法时，会处于假死状态
            using (System.Diagnostics.Process p = new System.Diagnostics.Process())
            {
                p.StartInfo.FileName = CmdPath;
                p.StartInfo.UseShellExecute = false;        //是否使用操作系统shell启动
                p.StartInfo.RedirectStandardInput = true;   //接受来自调用程序的输入信息
                p.StartInfo.RedirectStandardOutput = true;  //由调用程序获取输出信息
                p.StartInfo.RedirectStandardError = true;   //重定向标准错误输出
                p.StartInfo.CreateNoWindow = true;          //不显示程序窗口
                p.Start();//启动程序

                //向cmd窗口写入命令
                p.StandardInput.WriteLine(cmd);
                p.StandardInput.AutoFlush = true;

                //获取cmd窗口的输出信息
                output = p.StandardOutput.ReadToEnd();
                p.WaitForExit();//等待程序执行完退出进程
                p.Close();
            }
        }
   
    private void button_pause_Click(object sender, EventArgs e)//暂停按钮
        {
            if(flag==1)
            {
                if (button_pause.Text == "暂停")
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
            
        }

        private void btn_start_Click(object sender, EventArgs e)//开始按钮
        {
            if (button_pause.Text == "暂停"&&flag==0)

            {
                flag = 1;
                RunCmd(cmd, out output);
                sr = new StreamReader(@"qa.txt");
                if ((line_q = sr.ReadLine()) != null)
                {
                    label_question.Text = line_q;
                    timer1.Start();
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
        private void button_confirm_Click(object sender, EventArgs e)//确定按钮
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
        private void timer1_Tick(object sender, EventArgs e)//计时器
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
