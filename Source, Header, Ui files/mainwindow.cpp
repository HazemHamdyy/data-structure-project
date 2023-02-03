#include "mainwindow.h"

#include<QDebug>

vector<string> xmlVector;
Tree* XML_Tree;
Graph* graph;
vector <err_data> error_vector;
QString filePath;
string dataToBeSaved;
bool fileOpened;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Open file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", tr("XML Files (*.xml) ;; Text Files (*.txt)"));
    filePath = fileName;
    string fileNameString = fileName.toStdString();
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in(&file);
    xmlVector = file_to_vector(fileNameString);
    XML_Tree = new Tree();
    XML_Tree->bulid_xml_tree(xmlVector);
    graph = new Graph();
    graph->create_useres_vector(XML_Tree->getRoot());

    ui->plainTextEdit->setPlainText(in.readAll());
    ui->label->setText(fileName);
    fileOpened = true;
    //file.close();
}


void MainWindow::on_actionOpen_triggered()
{
    //Open File
    on_pushButton_clicked();
}


void MainWindow::on_pushButton_3_clicked()
{
    //Format
    if(fileOpened) {
        string formattedXml = Format(xmlVector);
        dataToBeSaved = formattedXml;
        ui->plainTextEdit->setPlainText(QString::fromStdString(formattedXml));
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    //Minify

    if (fileOpened) {
        string minified = Minify(xmlVector);
        dataToBeSaved = minified;
        ui->plainTextEdit->setPlainText(QString::fromStdString(minified));
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    // Convert JSON
    if (fileOpened){
        string json = convert_to_json(XML_Tree->getRoot());
        dataToBeSaved = json;
        ui->plainTextEdit->setPlainText(QString::fromStdString(json));
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    //Check Consistency
    if (fileOpened) {
        if (check_consistency(xmlVector)) {
            QMessageBox::information(0, "info", "XML file is consistent");
        }
        else
            QMessageBox::warning(0, "info", "XML file is inconsistent!");
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    // Check Error
    if (fileOpened) {
        ui->plainTextEdit->clear();
        error_vector = detect_error(xmlVector);
        if (!check_consistency(xmlVector)) {
            string errorString = printError(error_vector);
            ui->plainTextEdit->setPlainText(QString::fromStdString(errorString));
        }
        else
            QMessageBox::information(0, "info", "XML file is already consistent!");
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
    //Print errors in a pop up window.
    // Add line number to the left side.
}


void MainWindow::on_pushButton_11_clicked()
{
    // correct errors
    if (fileOpened) {
        error_vector = detect_error(xmlVector);
        if (!check_consistency(xmlVector)) {
            vector<string> correctedXmlVector = error_corrector(xmlVector, error_vector);
            xmlVector = correctedXmlVector;
            string formattedXml = Format(correctedXmlVector);
            dataToBeSaved = formattedXml;
            ui->plainTextEdit->setPlainText(QString::fromStdString(formattedXml));

        }
        else
            QMessageBox::information(0, "info", "XML file is already consistent!");
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_actionSave_triggered()
{
    //Save File
    std::ofstream outputFile(filePath.toStdString()); //open in constructor
    if (!outputFile)
    {
        QMessageBox::warning(0, "info", "File is not saved!");
    }
    outputFile << dataToBeSaved;
    outputFile.flush();
    outputFile.close();
    //QFile file(filePath);
    //if (!file.open(QIODevice::WriteOnly))
    //    QMessageBox::information(0, "info", file.errorString());
    //QTextStream out(&file);
    //QString text = ui->plainTextEdit->toPlainText();
    //out << text;
    //file.flush();
    //file.close();

}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "C://");
    std::ofstream outputFile(fileName.toStdString()); //open in constructor
    if (!outputFile)
    {
        QMessageBox::warning(0, "info", "File is not saved!");
    }
    outputFile << dataToBeSaved;
    outputFile.flush();
    outputFile.close();
    //QFile file(filePath
    //QFile file(fileName);
    //filePath = fileName;
    //if (!file.open(QIODevice::WriteOnly))
        //QMessageBox::information(0, "info", file.errorString());
    //QTextStream out(&file);

    //QString text = ui->plainTextEdit->toPlainText();
    //out << text;
    //file.flush();
    //file.close();
}


void MainWindow::on_actionFormat_triggered()
{
    on_pushButton_3_clicked();
}


void MainWindow::on_actionMinify_triggered()
{
    on_pushButton_4_clicked();
}


void MainWindow::on_actionConvert_to_JSON_triggered()
{
    on_pushButton_5_clicked();
}


void MainWindow::on_pushButton_2_clicked()
{
    //Compress
    if (fileOpened) {
        string compressed = removeSpacingAndUnique(filePath.toStdString());
        compressed = compressStringByHuffman(compressed);
        dataToBeSaved = compressed;
        ui->plainTextEdit->setPlainText(QString::fromStdString(compressed));
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
    //ui->plainTextEdit->clear();
}


void MainWindow::on_pushButton_10_clicked()
{
    //decompress
    if (fileOpened) {
        vector<string> decompressed = decompress(filePath.toStdString());
        string decompressedString = Format(decompressed);
        dataToBeSaved = decompressedString;
        ui->plainTextEdit->setPlainText(QString::fromStdString(decompressedString));
        xmlVector = decompressed;
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    //Graph info
    if (fileOpened) {
        User mostActive = graph->most_active_user();
        User mostInfluencer = graph->most_influencer_user();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText(QString::fromStdString("Most Active User is: \n" + mostActive.name + ", ID: " + mostActive.id));
        ui->plainTextEdit->appendPlainText(QString::fromStdString("\n\nMost Influencer User is: \n" + mostInfluencer.name + ", ID: " + mostInfluencer.id));
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    //Search
    if (fileOpened) {
        bool confirmed;
        QString text = QInputDialog::getText(this, tr("Enter the topic keyword"), tr("Topic:"), QLineEdit::Normal, "Enter Topic", &confirmed);
        if (confirmed && !text.isEmpty()){
            //function(text)
            ui->plainTextEdit->clear();
            vector<string> topic = graph->post_search(text.toStdString());
            if (topic.empty()) {
                QMessageBox::warning(0, "Warning", "There are no posts about this topic!");
            }
            else {
                ui->plainTextEdit->appendPlainText("Posts about " + text + ":\n");
                for (auto &i : topic) {
                    ui->plainTextEdit->appendPlainText(QString::fromStdString(i));
                    ui->plainTextEdit->appendPlainText("\n\n");
                }
            }
        }
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}


void MainWindow::on_pushButton_12_clicked()
{
    //Mutual Followers
    if (fileOpened){
        bool confirmed;
        QStringList list = InputDialog::getStrings(this, &confirmed);
        if (confirmed) {
            ui->plainTextEdit->clear();
            vector <User> mutual_followers = graph->mutual_followers(list[0].toStdString(), list[1].toStdString());
            if (mutual_followers.empty()) {
                QMessageBox::warning(0, "Warning", "No mutual followers exist between those two users!");
            }
            else {
                ui->plainTextEdit->appendPlainText("Mutual Followers for those users: \n\n");
                for (int i = 0; i < mutual_followers.size(); i++)
                {
                    ui->plainTextEdit->appendPlainText(QString::fromStdString(mutual_followers[i].name + " of id: " + mutual_followers[i].id + "\n"));
                }
            }
        }
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    //Suggest Followers
    if (fileOpened) {
        bool confirmed;
        QString text = QInputDialog::getText(this, tr("Enter the user ID"), tr("Suggest Followers:"), QLineEdit::Normal, QDir::home().dirName(), &confirmed);
        if (confirmed && !text.isEmpty()){
            //function(text)
            vector <User> suggested_followers = graph->follow_suggestion(text.toStdString());
            ui->plainTextEdit->clear();
            ui->plainTextEdit->appendPlainText("Suggested Followers for this user: \n\n");
            for (int i = 0; i < suggested_followers.size(); i++)
            {
                ui->plainTextEdit->appendPlainText(QString::fromStdString(suggested_followers[i].name + " of id: " + suggested_followers[i].id + "\n"));
            }
        }
    }
    else {
        QMessageBox::critical(0, "Warning", "You must open a File!");
    }
}


void MainWindow::on_actionCompress_triggered()
{
    on_pushButton_2_clicked();
}


void MainWindow::on_actionSearch_the_Graph_triggered()
{
    on_pushButton_6_clicked();
}

