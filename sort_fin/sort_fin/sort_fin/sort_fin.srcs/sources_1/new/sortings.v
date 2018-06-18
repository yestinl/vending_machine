`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/01/03 15:31:12
// Design Name: 
// Module Name: sortings
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// ����
// �󣨴������ϣ�Ti-FPGA: ��ת���Ӹߵ��ͣ���PF4-B17 PN0-A16 PN1-A14 ���1��PF0-A18 ���2��PK7-F14
// �ң��������ϣ�pwm���-FPGA����ת-B16 ���1-A15 ���2-A13
// �£�
// �󣨴������ϣ�Ti-FPGA: ��ת1���Ӹߵ��ͣ���PF4-B17 PN0-A16 PN1-A14 ��ת2��PK6-A18 PH1-F14 PH0-B14 ���1��PF0-C14 ���2��PK7-A11
// �ң��������ϣ�pwm���-FPGA����ת1-B16 ��ת2-A15 ���1-A13 ���2-B18
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module uart(
     input clk,
     input [2:0]rotate_servo,//��ɫ���ʵ����ת�����ͬ�Ƕ�
//     input [2:0]rotate1_servo,//��ɫ���ʵ����ת�����ͬ�Ƕ�
//     input [2:0]rotate2_servo,//��ɫ���ʵ����ת�����ͬ�Ƕ�
     input push1_servo,//���ƴ�����1�Ƿ�ת��
     input push2_servo,//���ƴ�����2�Ƿ�ת��
     output reg pwm_rotate,//��ת���PWM
//     output reg pwm_rotate1,//��ת���1PWM
//     output reg pwm_rotate2,//��ת���2PWM
     output reg pwm_push1,//������1PWM
     output reg pwm_push2//������2PWM
    );
    parameter angle1=8'd22;//6����ͬ�Ƕ�
    parameter angle2=8'd19;
    parameter angle3=8'd16;
    parameter angle4=8'd13;
    parameter angle5=8'd10;
    parameter angle6=8'd8;
    
//    parameter angle1=8'd25;//6����ͬ�Ƕ�
//    parameter angle2=8'd24;
//    parameter angle3=8'd23;
//    parameter angle4=8'd20;
//    parameter angle5=8'd17;
//    parameter angle6=8'd7;

    parameter angle_push1=8'd16;
    parameter angle_push2=8'd10;
    
    reg[31:0] count;
    reg[31:0] count1;
    reg[5:0] pwm_r;
    reg[1:0] pwm_p;
    
    always@(posedge clk)
    begin
        count=count+1;
        if(count==32'd10010)
        begin
            count=0;
            count1=count1+1;
        end
        if(count1==8'd1)
        begin
            pwm_r[0]<=1;
            pwm_r[1]<=1;
            pwm_r[2]<=1;
            pwm_r[3]<=1;
            pwm_r[4]<=1;
            pwm_r[5]<=1;
            pwm_p[0]<=1;
            pwm_p[1]<=1;
         end   
        else if(count1==angle1)
            pwm_r[0]<=0;
        else if(count1==angle2)
            pwm_r[1]<=0;
        else if(count1==angle3)
            pwm_r[2]<=0;
        else if(count1==angle4)
            pwm_r[3]<=0;
        else if(count1==angle5)
            pwm_r[4]<=0;
        else if(count1==angle6)
            pwm_r[5]<=0;
        else if(count1==angle_push1)
            pwm_p[0]<=0;
        else if(count1==angle_push2)
            pwm_p[1]<=1;
        else if(count1==16'd200)
        count1=0;
    end
    
    always@(rotate_servo)
        case(rotate_servo)
            0:pwm_rotate<=pwm_r[0];
            1:pwm_rotate<=pwm_r[1];
            2:pwm_rotate<=pwm_r[2];
            3:pwm_rotate<=pwm_r[3];
            4:pwm_rotate<=pwm_r[4];
            5:pwm_rotate<=pwm_r[5];
        endcase
    
//    always@(rotate1_servo)
//        case(rotate1_servo)
//            0:pwm_rotate1<=pwm[0];
//            1:pwm_rotate1<=pwm[1];
//            2:pwm_rotate1<=pwm[2];
//            3:pwm_rotate1<=pwm[3];
//            4:pwm_rotate1<=pwm[4];
//            5:pwm_rotate1<=pwm[5];
//        endcase
 
            
            
//    always@(rotate2_servo)
//          case(rotate2_servo)
//              0:pwm_rotate2<=pwm[0];
//              1:pwm_rotate2<=pwm[1];
//              2:pwm_rotate2<=pwm[2];
//              3:pwm_rotate2<=pwm[3];
//              4:pwm_rotate2<=pwm[4];
//              5:pwm_rotate2<=pwm[5];
//          endcase


    always@(push1_servo)
        case(push1_servo)
            0:pwm_push1<=pwm_r[0];
            1:pwm_push1<=pwm_p[0];
        endcase
        
    always@(push2_servo)
        case(push2_servo)
            0:pwm_push2<=pwm_r[0];
            1:pwm_push2<=pwm_p[1];
        endcase
endmodule
