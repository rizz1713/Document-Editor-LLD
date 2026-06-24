#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class documentEditor{
    private:
    vector<string> docelement;
    string renderDocment;

    public:

    void addText(string text){
        docelement.push_back(text);
    }
    void addImage(string path){
        docelement.push_back(path);
    }

    string renderDocument(){
        string result;
        if(renderDocment.empty()){
            for(auto element : docelement){
                if(element.size()>4 && (element.substr(element.size()-4)==".jpg"|| element.substr(element.size()-4)==".png")){
                    result+="[Image:"+element+"]"+"\n";
                }else{
                    result+=element+"\n";
                }
            }
            renderDocment = result;
        }
        return renderDocment;
    }
    string saveToFile(){
        ofstream file("doc.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"Document saved to doc.txt"<<endl;
        }
        else{
            cout<<"Error : Unable to open file"<<endl;
        }
    }
};
int main(){
    documentEditor editor;
    editor.addText("Hello");
    editor.addImage("pic.png");
    cout<< editor.renderDocument()<<endl;
    editor.saveToFile();

    return 0;
}