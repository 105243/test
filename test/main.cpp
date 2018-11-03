#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>


QFile file("names.txt");
QTextStream input(&file);
QString string;
QStringList temp;
QString names[20][4];

void readFile() {

    int i=0;
    while(!input.atEnd()) {

        string = input.readLine();
        temp = string.split(QRegExp("\\s+"), QString::SkipEmptyParts);

        for (int j=0; j<temp.size(); j++) {

            names[i][j] = temp[j];

        }
        i++;
    }

}


int main() {

    if (!file.exists()){
        qDebug() << "File \"names.txt\" not found";
        return -1;
    }
     if(!file.open(QFile::ReadWrite | QFile::Text))  {
         qDebug() << "Can't read file \"names.txt\"";
         return -1;
     }

    readFile();
    return 0;
}
