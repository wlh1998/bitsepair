namespace 四则运算1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btn_start = new System.Windows.Forms.Button();
            this.label_djs = new System.Windows.Forms.Label();
            this.label_time = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label_timu = new System.Windows.Forms.Label();
            this.label_question = new System.Windows.Forms.Label();
            this.label_second = new System.Windows.Forms.Label();
            this.label_daan = new System.Windows.Forms.Label();
            this.textBox_answer = new System.Windows.Forms.TextBox();
            this.button_confirm = new System.Windows.Forms.Button();
            this.openFile = new System.Windows.Forms.OpenFileDialog();
            this.textBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label_right = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label_sum = new System.Windows.Forms.Label();
            this.button_pause = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_start
            // 
            this.btn_start.BackColor = System.Drawing.SystemColors.ControlLight;
            this.btn_start.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btn_start.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btn_start.Font = new System.Drawing.Font("华文彩云", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.btn_start.Location = new System.Drawing.Point(581, 12);
            this.btn_start.Name = "btn_start";
            this.btn_start.Size = new System.Drawing.Size(91, 40);
            this.btn_start.TabIndex = 0;
            this.btn_start.Text = "开始";
            this.btn_start.UseVisualStyleBackColor = false;
            this.btn_start.Click += new System.EventHandler(this.btn_start_Click);
            // 
            // label_djs
            // 
            this.label_djs.AutoSize = true;
            this.label_djs.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_djs.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_djs.Location = new System.Drawing.Point(69, 47);
            this.label_djs.Name = "label_djs";
            this.label_djs.Size = new System.Drawing.Size(93, 20);
            this.label_djs.TabIndex = 1;
            this.label_djs.Text = "倒计时：";
            // 
            // label_time
            // 
            this.label_time.AutoSize = true;
            this.label_time.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_time.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_time.Location = new System.Drawing.Point(154, 47);
            this.label_time.Name = "label_time";
            this.label_time.Size = new System.Drawing.Size(34, 21);
            this.label_time.TabIndex = 2;
            this.label_time.Text = "20";
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label_timu
            // 
            this.label_timu.AutoSize = true;
            this.label_timu.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_timu.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_timu.Location = new System.Drawing.Point(69, 96);
            this.label_timu.Name = "label_timu";
            this.label_timu.Size = new System.Drawing.Size(76, 21);
            this.label_timu.TabIndex = 3;
            this.label_timu.Text = "题目：";
            // 
            // label_question
            // 
            this.label_question.AutoSize = true;
            this.label_question.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_question.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_question.Location = new System.Drawing.Point(151, 96);
            this.label_question.Name = "label_question";
            this.label_question.Size = new System.Drawing.Size(346, 21);
            this.label_question.TabIndex = 4;
            this.label_question.Text = "                            ";
            // 
            // label_second
            // 
            this.label_second.AutoSize = true;
            this.label_second.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_second.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_second.Location = new System.Drawing.Point(194, 47);
            this.label_second.Name = "label_second";
            this.label_second.Size = new System.Drawing.Size(22, 21);
            this.label_second.TabIndex = 5;
            this.label_second.Text = "S";
            // 
            // label_daan
            // 
            this.label_daan.AutoSize = true;
            this.label_daan.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_daan.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_daan.Location = new System.Drawing.Point(69, 141);
            this.label_daan.Name = "label_daan";
            this.label_daan.Size = new System.Drawing.Size(164, 21);
            this.label_daan.TabIndex = 6;
            this.label_daan.Text = "输入你的答案：";
            // 
            // textBox_answer
            // 
            this.textBox_answer.Location = new System.Drawing.Point(271, 141);
            this.textBox_answer.Name = "textBox_answer";
            this.textBox_answer.Size = new System.Drawing.Size(180, 21);
            this.textBox_answer.TabIndex = 7;
            // 
            // button_confirm
            // 
            this.button_confirm.Font = new System.Drawing.Font("华文彩云", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_confirm.ForeColor = System.Drawing.Color.Black;
            this.button_confirm.Location = new System.Drawing.Point(502, 131);
            this.button_confirm.Name = "button_confirm";
            this.button_confirm.Size = new System.Drawing.Size(91, 40);
            this.button_confirm.TabIndex = 8;
            this.button_confirm.Text = "确定";
            this.button_confirm.UseVisualStyleBackColor = true;
            this.button_confirm.Click += new System.EventHandler(this.button_confirm_Click);
            // 
            // openFile
            // 
            this.openFile.FileName = "qa";
            this.openFile.InitialDirectory = "C:\\Users\\lenovo\\Desktop\\四则运算";
            // 
            // textBox
            // 
            this.textBox.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox.Location = new System.Drawing.Point(94, 245);
            this.textBox.Multiline = true;
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(458, 143);
            this.textBox.TabIndex = 10;
            this.textBox.Text = "错题记录：";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.Desktop;
            this.label1.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(69, 196);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 21);
            this.label1.TabIndex = 11;
            this.label1.Text = "正确率：";
            // 
            // label_right
            // 
            this.label_right.AutoSize = true;
            this.label_right.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_right.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_right.Location = new System.Drawing.Point(211, 196);
            this.label_right.Name = "label_right";
            this.label_right.Size = new System.Drawing.Size(22, 21);
            this.label_right.TabIndex = 12;
            this.label_right.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Desktop;
            this.label3.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Location = new System.Drawing.Point(239, 196);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(22, 21);
            this.label3.TabIndex = 13;
            this.label3.Text = "/";
            // 
            // label_sum
            // 
            this.label_sum.AutoSize = true;
            this.label_sum.BackColor = System.Drawing.SystemColors.Desktop;
            this.label_sum.Font = new System.Drawing.Font("宋体", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_sum.Location = new System.Drawing.Point(267, 196);
            this.label_sum.Name = "label_sum";
            this.label_sum.Size = new System.Drawing.Size(22, 21);
            this.label_sum.TabIndex = 14;
            this.label_sum.Text = "0";
            // 
            // button_pause
            // 
            this.button_pause.BackColor = System.Drawing.SystemColors.ControlLight;
            this.button_pause.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button_pause.Font = new System.Drawing.Font("华文彩云", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button_pause.Location = new System.Drawing.Point(581, 58);
            this.button_pause.Name = "button_pause";
            this.button_pause.Size = new System.Drawing.Size(91, 40);
            this.button_pause.TabIndex = 15;
            this.button_pause.Text = "暂停";
            this.button_pause.UseVisualStyleBackColor = false;
            this.button_pause.Click += new System.EventHandler(this.button_pause_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(684, 420);
            this.Controls.Add(this.button_pause);
            this.Controls.Add(this.label_sum);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label_right);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.button_confirm);
            this.Controls.Add(this.textBox_answer);
            this.Controls.Add(this.label_daan);
            this.Controls.Add(this.label_second);
            this.Controls.Add(this.label_question);
            this.Controls.Add(this.label_timu);
            this.Controls.Add(this.label_time);
            this.Controls.Add(this.label_djs);
            this.Controls.Add(this.btn_start);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "四则运算练习";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_start;
        private System.Windows.Forms.Label label_djs;
        private System.Windows.Forms.Label label_time;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label_timu;
        private System.Windows.Forms.Label label_question;
        private System.Windows.Forms.Label label_second;
        private System.Windows.Forms.Label label_daan;
        private System.Windows.Forms.TextBox textBox_answer;
        private System.Windows.Forms.Button button_confirm;
        private System.Windows.Forms.OpenFileDialog openFile;
        private System.Windows.Forms.TextBox textBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label_right;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label_sum;
        private System.Windows.Forms.Button button_pause;
    }
}

