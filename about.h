#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

namespace Ui {
class About;
}
/**
 * @brief The About class is a child of QWidget which shows a brief description of the project
 * and who developed it.
 */
class About : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief This coonstructor sets up the UI
     * @param parent refers to the QWidget that calls this constructor
     */
    explicit About(QWidget *parent = 0);

    ~About(); //!< The Destructor of this class deletes the UI

private:
    Ui::About *ui;
};

#endif // ABOUT_H
