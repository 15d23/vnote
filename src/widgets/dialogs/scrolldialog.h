#ifndef SCROLLDIALOG_H
#define SCROLLDIALOG_H

#include "dialog.h"

class QScrollArea;

namespace vnotex
{
    class ScrollDialog : public Dialog
    {
        Q_OBJECT
    public:
        ScrollDialog(QWidget *p_parent = nullptr, Qt::WindowFlags p_flags = Qt::WindowFlags());

        void setCentralWidget(QWidget *p_widget) Q_DECL_OVERRIDE;

        void resizeToHideScrollBarLater(bool p_vertical, bool p_horizontal);

    protected:
        void showEvent(QShowEvent *p_event) Q_DECL_OVERRIDE;

    private:
        QScrollArea *m_scrollArea = nullptr;
    };
} // ns vnotex

#endif // SCROLLDIALOG_H
