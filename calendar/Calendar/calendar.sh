#!/bin/bash

echo "-----------------------------------------------测试帮助程序---------------------------------------------------"
echo ""
echo "Shell测试：help列表的获取"
./calendar help
echo "Shell测试：修改密码help信息"
./calendar help changepassword
echo "Shell测试：删除用户help信息"
./calendar help deleteuser
echo "Shell测试：帮助help信息"
./calendar help help
echo "Shell测试：run模式help信息"
./calendar help run
echo "Shell测试：添加任务help信息"
./calendar help addtask
echo "Shell测试：删除任务help信息"
./calendar help deletetask
echo "Shell测试：显示任务help信息"
./calendar help displaytask
echo "Shell测试：显示错误函数的help信息"
./calendar help hungry
echo "Shell测试：help错误参数个数情况"
./calendar help run 1 3

echo ""
echo "------------------------测试用户的注册/修改密码/登陆/错误密码登陆/删除用户失败/删除用户------------------------------"
echo ""
echo "Shell测试：添加用户，用户名：tmp;用户密码：123456"
./calendar tmp 123456
echo "Shell测试：修改用户密码，用户名：tmp;用户原密码：123456；用户新密码：234567"
./calendar changepassword tmp 123456 234567
echo "Shell测试：修改用户密码，用户不存在或密码错误的情况"
./calendar changepassword qsq 121212 121212
echo "Shell测试：修改用户密码，参数错误的情况"
./calendar changepassword 34134 1231 122 3
echo "Shell测试：用户登录，用户名：tmp;输入密码：123456；用户正确密码：234567"
./calendar tmp 123456
echo "Shell测试：用户登录，用户名：tmp;输入密码：234567"
./calendar tmp 234567
echo "Shell测试：用户删除，密码错误的情况。用户名：tmp;输入密码：123456；用户正确密码：234567"
./calendar deleteuser tmp 123456
echo "Shell测试：用户删除，用户不存在的情况，用户名：阿巴"
./calendar deleteuser 阿巴 123456
echo "Shell测试：用户删除，参数错误的情况"
./calendar deleteuser tmp 234567 123 123 123
echo "Shell测试：用户登录，用户名和密码正确的情况。用户名：tmp;输入密码：123456"
./calendar deleteuser tmp 234567
echo ""
echo "Shell测试：用户添加，用户名过长的情况"
./calendar aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 123456
echo "Shell测试：错误指令的测试"
./calendar as dhsau 
echo "Shell测试：未输入指令的测试"
./calendar

echo ""
echo "---------------------------------测试用户日程的添加/查找/删除以及一些错误提示--------------------------------------"
echo "先用Shell指令重新创建一个账户，用户名yyds；密码fakernb"
./calendar yyds fakernb
echo ""
echo "Shell测试：测试用户日程的添加功能： "
echo "测试1：添加一个正常任务，任务名：测试1；提醒时间：2023-12-3 15：40；开始时间：2023-12-4 0：0；优先级：高；分类：大作业"
./calendar yyds fakernb addtask 测试1 2023 12 3 15 40 2023 12 4 0 0 高 大作业
echo "测试2：添加优先级为缺省的任务，任务名：测试2,提醒时间：2024-1-1 1：1；开始时间：2024-2-2 0：0,分类：大作业"
./calendar yyds fakernb addtask 测试2 2024 1 1 1 1 2024 2 2 0 0 大作业
echo "测试3：添加分类为缺省的任务，任务名：测试3,提醒时间：2024-2-2 2：2；开始时间：2024-3-3 3：3,优先级：低"
./calendar yyds fakernb addtask 测试3 2024 2 2 2 2 2024 3 3 3 3 低
echo "测试4：添加分类和优先级皆为缺省的任务，任务名：测试4,提醒时间：2024-3-3 3：3；开始时间：2024-4-4 4：4"
./calendar yyds fakernb addtask 测试4 2024 3 3 3 3 2024 4 4 4 4
echo "Shell测试效果：正确添加4个任务效果："
./calendar yyds fakernb displaytask 5
echo "测试5：添加任务，用户名过长错误，任务名：测试5,提醒时间：2024-4-4 4：4；开始时间：2024-5-5 5：5"
./calendar 原来你也玩原神原神启动 mhynb addtask 测试5 2024 4 4 4 4 2024 5 5 5 5
echo "测试6：添加任务，格式错误，任务名：测试6,提醒时间：2024-4-4 4：4；开始时间：2024-5-5 5：5"
./calendar 原来你也玩原神 mhynb addtask add 测试6 2024 4 4 4 4 2024 5 5 5 5
echo "测试7：添加任务，日期异常，任务名：测试7,提醒时间：2024-4-44 4：4；开始时间：2024-5-5 5：555"
./calendar 原来你也玩原神 mhynb addtask 测试7 2024 4 44 4 4 2024 5 5 5 555
echo "测试8：添加任务，开始时间小于当前时间，任务名：测试8,提醒时间：2022-4-4 4：4；开始时间：2022-5-5 5：5"
./calendar 原来你也玩原神 mhynb addtask 测试8 2022 4 4 4 4 2022 5 5 5 5
echo "测试9：添加任务，提醒时间大于开始时间，任务名：测试9,提醒时间：2024-4-4 4：4；开始时间：2024-3-5 5：5"
./calendar 原来你也玩原神 mhynb addtask 测试9 2024 4 4 4 4 2024 3 5 5 5
echo "测试10：添加任务，存在相同开始时间的日程，任务名：测试10,提醒时间：2024-4-4 4：4；开始时间：2024-3-5 5：5"
./calendar 原来你也玩原神 mhynb addtask 测试10 2024 4 4 4 4 2024 3 5 5 5
echo "测试11：添加任务，分类名称过长，任务名：测试11,提醒时间：2024-4-5 4：4；开始时间：2024-5-5 5：5"
./calendar 原来你也玩原神 mhynb addtask 测试11 2024 4 5 4 4 2024 5 5 5 5 分类名称过长啊对对对
echo "测试12：添加任务，任务名过长错误，任务名：测试12任务名过长,提醒时间：2024-4-4 4：4；开始时间：2024-5-5 5：5"
./calendar 原来你也玩原神 mhynb addtask 测试12任务名过长原神怎么你了 2024 4 4 4 4 2024 5 5 5 5
echo "Shell测试效果：添加任务效果："
./calendar 原来你也玩原神 mhynb displaytask 5



echo ""
echo ""
echo "Shell测试：删除前任务："
./calendar 原来你也玩原神 mhynb displaytask 5
echo "Shell测试效果：测试用户日程的删除功能： "
echo "测试1：正常删除一个任务，任务名：测试8 任务id：1"
./calendar 原来你也玩原神 mhynb deletetask 1
echo "Shell测试效果：删除后任务："
./calendar 原来你也玩原神 mhynb displaytask 5
echo "测试2：删除任务id不存在，任务id：3"
./calendar 原来你也玩原神 mhynb deletetask 3
echo "测试3：删除任务id不是整数，任务id：3.5"
./calendar 原来你也玩原神 mhynb deletetask 3.5
echo "测试4：删除任务参数错误，任务id：3"
./calendar 原来你也玩原神 mhynb deletetask 3 3
echo "测试5：删除任务的用户密码错误，任务id：1"
./calendar 原来你也玩原神 mhynbnb deletetask 3
echo "测试6：删除任务参数未给定"
./calendar 原来你也玩原神 mhynb deletetask



echo ""
echo ""
echo "Shell测试：测试用户日程的显示功能： "
echo "测试1：正常显示用户所有任务，模式5"
./calendar 原来你也玩原神 mhynb displaytask 5
echo "测试2：正常显示用户某年的任务，模式1"
./calendar 原来你也玩原神 mhynb displaytask 1 2024
echo "测试3：正常显示用户某月任务，模式2"
./calendar 原来你也玩原神 mhynb displaytask 2 2024 3
echo "测试4：正常显示用户某日任务，模式3"
./calendar 原来你也玩原神 mhynb displaytask 3 2024 3 5
echo "测试5：正常显示用户某日任务（无任务），模式3，"
./calendar 原来你也玩原神 mhynb displaytask 3 2024 3 6
echo "测试6：显示用户所有任务但密码错误，模式5"
./calendar 原来你也玩原神 mhynbnb displaytask 5
echo "测试7：显示用户某日任务但日期格式错误，模式3"
./calendar 原来你也玩原神 mhynb displaytask 3 2024 3 5 3
echo "测试8：显示用户某日任务但日期不存在，模式3"
./calendar 原来你也玩原神 mhynb displaytask 3 2024 3 53
echo "测试9：显示用户任务，模式不存在，模式6"
./calendar 原来你也玩原神 mhynb displaytask 6
echo "测试10：显示用户任务，模式未给定"
./calendar 原来你也玩原神 mhynb displaytask



