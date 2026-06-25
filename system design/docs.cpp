#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class DocumentElement{
    public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
    string text;
    public:
    TextElement(string text){
        this->text = text;
    }
    string render(){
        return text;
    }
};

class ImageElement : public DocumentElement{
    private:
    string path;
    public:
    ImageElement(string path){
        this->path = path;
    }
    string render(){
        return "[Image :"+path+" ]";
    }
};

class NewLine : public DocumentElement{
    public:
    string render(){
        return "\n";
    }
};

class tabSpace : public DocumentElement{
    public:
    string render(){
        return "\t";
    }
};
class Persistance{
    public:
    virtual void save(string data) = 0;
};

class saveToFile : public Persistance{
    public:
    void save(string data){
        ofstream file("doc.txt");
        if(file.is_open()){
            file<<data;
            file.close();
            cout<<"File saved to doc.txt";
        }else{
            cout<<"Error: unable to open file";
        }
    }    
};

class saveToDB : public Persistance{
    public:
    void save(string data){
        
    }

};

class Document{
    private:
    vector<DocumentElement*> docElements;
    public:
    void addElement(DocumentElement* element)
    {
        docElements.push_back(element);
    }
    string render(){
        string result;
        for(auto element:docElements){
            result+=element->render();
        }
        return result;
    }
};

class DocumentEditor{
    private:
    Document* document;
    Persistance* storage;
    string renderdoc;

    public:

    DocumentEditor(Document* document,Persistance* storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string path){
        document->addElement(new ImageElement(path));
    }

    void addNewLine(){
        document->addElement(new NewLine());
    }

    void addTabSpace(){
        document->addElement(new tabSpace());
    }

    string renderDocument(){
        if(renderdoc.empty()){
            renderdoc = document->render();
        }
        return renderdoc;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
};

int main(){
    Document* document = new Document();
    Persistance* storage = new saveToFile();
    DocumentEditor* editor = new DocumentEditor(document,storage);

    editor->addText("Hello , I am chaitanya");
    editor->addNewLine();
    editor->addImage("picture.jpg");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Idented text after tab space");

    cout<<editor->renderDocument()<<endl;
    editor->saveDocument();
    return 0;
}