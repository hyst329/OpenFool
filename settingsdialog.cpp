#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QSettings *settings, QWidget *parent)
    : QDialog(parent), ui(new Ui::SettingsDialog), settings(settings)
{
    ui->setupUi(this);
    ui->lineEditPlayer1Name->setText(
        settings->value("players/name1", "South").toString());
    ui->lineEditPlayer2Name->setText(
        settings->value("players/name2", "West").toString());
    ui->lineEditPlayer3Name->setText(
        settings->value("players/name3", "North").toString());
    ui->lineEditPlayer4Name->setText(
        settings->value("players/name4", "East").toString());
}

SettingsDialog::~SettingsDialog() { delete ui; }

void SettingsDialog::saveSettings()
{
    settings->setValue("players/name1", ui->lineEditPlayer1Name->text());
    settings->setValue("players/name2", ui->lineEditPlayer2Name->text());
    settings->setValue("players/name3", ui->lineEditPlayer3Name->text());
    settings->setValue("players/name4", ui->lineEditPlayer4Name->text());
}

void SettingsDialog::accept()
{
    saveSettings();
    QDialog::accept();
}

void SettingsDialog::apply() { saveSettings(); }

void SettingsDialog::onClick(QAbstractButton *button)
{
    if (ui->buttonBox->standardButton(button) == QDialogButtonBox::Apply)
        apply();
}
