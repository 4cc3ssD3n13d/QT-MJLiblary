#include <QtCore>

QString RandomString(int StringLength = 10){
   srand(time(0));
   QString Characters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   QString RandomString;
   for(int i = 0; i < StringLength; ++i){
       int index = rand() % Characters.length();
       QChar nextChar = Characters.at(index);
       RandomString.append(nextChar);
   }
   return RandomString;
}
