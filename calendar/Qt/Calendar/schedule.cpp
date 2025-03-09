#include "schedule.h"

scheduleList::scheduleList(string user):username(user){
    taskNumber=1;
}

void scheduleList::addTask(string name,time_t aT,time_t sT,int prio,string cla,int number){
    int id=number;
    if(!number){
        id=taskNumber;
    }
    schedule tmp(name,aT,sT,id,prio,cla);
    pair<map<long int, schedule>::iterator, bool> InsertPair1;
    InsertPair1 = taskList.insert(pair<long int, schedule>(sT, tmp));
    if(!number){
        if(InsertPair1.second){
            string ID=to_string(id);
            QString a=str2qstr(ID);
            QMessageBox::information(NULL,"提示","成功添加日程,id为"+a);
            taskNumber++;
        }
    }
}

void scheduleList::loadFile(){
     char filename[40]="./";
     char a[5]=".txt";
     strcat(filename,username.data());
     strcat(filename,a);
     FILE *fp = fopen(filename, "r");
     if (fp == NULL)
     {
         QMessageBox::information(NULL,"错误","读取文件失败，无法打开文件");
         return;
     }
     char taskname[31];
     char classification[22];
     long int alertTime, startTime;
     int priority;
     int id;
     while (!feof(fp)){
         int pout = fscanf(fp, "%d %s %ld %ld %s %d\n", &id, taskname, &alertTime, &startTime, classification, &priority);
         if (pout == EOF){
             break;
         }
         else if (pout != 6){
             QMessageBox::information(NULL,"错误","文件无法正确读取");
             return;
         }
         string task=taskname;
         string classifi=classification;
         addTask(task,alertTime,startTime,priority,classifi,id);
         if (id >= taskNumber){
             taskNumber = id + 1;
         }

     }
     fclose(fp);
     return;


}

void scheduleList::saveFile(){
    char filename[40]="./";
    char a[5]=".txt";
    strcat(filename,username.data());
    strcat(filename,a);
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        QMessageBox::information(NULL,"错误","创建/保存文件失败，无法创建/打开文件");
        return;
    }
    for (auto it : taskList){
        fprintf(fp, "%d %s %ld %ld %s %d\n", it.second.id, it.second.taskname.c_str(), it.second.alertTime, it.second.startTime, it.second.classification.c_str(), it.second.priority);
    }
    fclose(fp);
    return;
}

bool scheduleList::isUniqueTime(long int time){
    bool flag = true;
    for (auto it : taskList){
        if(it.second.startTime==time){
            flag = false;
            break;
        }
    }
    return flag;
}

void scheduleList::delTask(int id,bool flag1){
    bool flag=false;
    for (auto it : taskList){
        if(it.second.id==id){
            flag=true;
            long int time=it.first;
            taskList.erase(time);
            if(flag1) QMessageBox::information(NULL,"提示","删除成功！");
            break;
        }
    }
    if(!flag){
        QMessageBox::critical(NULL,"错误","日程id不存在");
    }
    return;
}

bool scheduleList::isExistId(int id){
    bool flag=false;
    for (auto it : taskList){
        if(it.second.id==id){
            flag=true;
            break;
        }
    }
    return flag;
}

void scheduleList::getInfo(int id,string &task,time_t &sT,time_t &aT,int &prio,string &classifi){
    for (auto it : taskList){
        if(it.second.id==id){
            task=it.second.taskname;
            aT=it.second.alertTime;
            sT=it.second.startTime;
            prio=it.second.priority;
            classifi=it.second.classification;
        }
    }
    return;
}

time_t scheduleList::getStartTime(int id){
    time_t tmp=0;
    for (auto it : taskList){
        if(it.second.id==id){
            tmp=it.second.startTime;
            break;
        }
    }
    return tmp;
}

void scheduleList::addStatic(QTableWidget *&table,QString Qtaskname,QString Qclassifi,int priority,time_t time1,time_t time2){
    bool flag_task=true;
    bool flag_class=true;
    bool flag_prio=true;
    if(!QString::compare(Qtaskname,"")){
        flag_task=false;
    }
    if(!QString::compare(Qclassifi,"")){
        flag_class=false;
    }
    if(priority==0){
        flag_prio=false;
    }
    int RowCont;
    string taskname,classification,Id;
    QString Qprio,Qtask,Qclass,QaT,QsT,Qid;
    QDateTime QalertTime,QstartTime;
    int prio,id;
    time_t sT;
    time_t aT;
    for (auto it : taskList){
        bool flag=true;
        taskname=it.second.taskname;
        classification=it.second.classification;
        aT=it.second.alertTime;
        sT=it.second.startTime;
        id=it.second.id;
        prio=it.second.priority;
        Qtask=str2qstr(taskname);
        Qclass=str2qstr(classification);
        if(flag_task){
            if(QString::compare(Qtask,Qtaskname)!=0){
                flag=false;
            }
        }
        if(flag_class){
            if(QString::compare(Qclass,Qclassifi)!=0){
                flag=false;
            }
        }
        if(flag_prio){
            if(prio!=priority){
                flag=false;
            }
        }
        if(sT<time1){
            flag=false;
        }
        if(sT>time2){
            flag=false;
        }
        if(flag){
            switch (prio) {
            case 1:
                Qprio="低";
                break;
            case 2:
                Qprio="中";
                break;
            case 3:
                Qprio="高";
                break;
            }
            Id=to_string(id);
            Qid=str2qstr(Id);
            QalertTime=QDateTime::fromTime_t(aT);
            QstartTime=QDateTime::fromTime_t(sT);
            QaT=QalertTime.toString("yyyy-MM-dd HH:mm:ss");
            QsT=QstartTime.toString("yyyy-MM-dd HH:mm:ss");

            RowCont=table->rowCount();
            table->insertRow(RowCont);
            table->setItem(RowCont,0,new QTableWidgetItem(Qid));
            table->setItem(RowCont,1,new QTableWidgetItem(Qtask));
            table->setItem(RowCont,2,new QTableWidgetItem(QsT));
            table->setItem(RowCont,3,new QTableWidgetItem(QaT));
            table->setItem(RowCont,4,new QTableWidgetItem(Qprio));
            table->setItem(RowCont,5,new QTableWidgetItem(Qclass));
        }

    }

}





