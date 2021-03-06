from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(518, 150)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.label_ans = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift Light SemiCondensed")
        font.setPointSize(10)
        self.label_ans.setFont(font)
        self.label_ans.setObjectName("label_ans")
        self.gridLayout.addWidget(self.label_ans, 2, 0, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Minimum)
        self.gridLayout.addItem(spacerItem, 3, 3, 1, 1)
        self.input = QtWidgets.QLineEdit(self.centralwidget)
        self.input.setObjectName("input")
        self.gridLayout.addWidget(self.input, 1, 1, 1, 4)
        self.chooseBox = QtWidgets.QComboBox(self.centralwidget)
        self.chooseBox.setMinimumSize(QtCore.QSize(157, 0))
        font = QtGui.QFont()
        font.setFamily("Bahnschrift Light SemiCondensed")
        font.setPointSize(10)
        self.chooseBox.setFont(font)
        self.chooseBox.setObjectName("chooseBox")
        self.chooseBox.addItem("")
        self.chooseBox.addItem("")
        self.gridLayout.addWidget(self.chooseBox, 0, 0, 1, 1)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Policy.Minimum, QtWidgets.QSizePolicy.Policy.Expanding)
        self.gridLayout.addItem(spacerItem1, 4, 0, 1, 5)
        self.answer = QtWidgets.QLineEdit(self.centralwidget)
        self.answer.setObjectName("answer")
        self.gridLayout.addWidget(self.answer, 2, 1, 1, 4)
        self.label_input = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift Light SemiCondensed")
        font.setPointSize(10)
        self.label_input.setFont(font)
        self.label_input.setObjectName("label_input")
        self.gridLayout.addWidget(self.label_input, 1, 0, 1, 1)
        self.button = QtWidgets.QPushButton(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift Light SemiCondensed")
        font.setPointSize(10)
        self.button.setFont(font)
        self.button.setObjectName("button")
        self.gridLayout.addWidget(self.button, 3, 4, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 518, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_ans.setText(_translate("MainWindow", "??????????:"))
        self.chooseBox.setItemText(0, _translate("MainWindow", "?????????????????? ?????????????? 1"))
        self.chooseBox.setItemText(1, _translate("MainWindow", "?????????????????? ?????????????? 2"))
        self.label_input.setText(_translate("MainWindow", "?????????????? ??????????:"))
        self.button.setText(_translate("MainWindow", "??????????????????"))
