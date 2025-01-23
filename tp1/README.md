Vinicius Nascimento et Raquel Maciel Coelho <br>
TP1 C++ Group CyAI<br>
© 2024 ENSICAEN. All rights reserved.<br>
This code is the intellectual property of ENSICAEN and is subject to the institution's terms and conditions.
Unauthorized reproduction, distribution, or use is strictly prohibited

---

## Exécution :
-   utilisez QTCreator pour exécuter le code

---

### 1.2.2 Ouvrez le fichier main.pro
Commentaire à la fin du fichier.

### 1.2.3 Nous allons ici nous convaincre qu’il vaut mieux laisser à Qt/qmake le soin de produire un fichier Makefile à notre place.
En effet, utiliser les commandes 'qmake' ou 'CMake' est préférable, compte tenu de la complexité du fichier Makefile requis, vu le nombre de paramètres et l'extension du Makefile généré.

### 1.2.4 Lancez la compilation (
Il suffit d'exécuter le programme.

---

### 2.1 Ajustez si besoin les positions des différents widgets 
Pas nécessaire, le programme est initialisé dans la taille correcte, bien que la taille relative soit une technique plus appropriée.

### 2.2 Modifiez le titre (Window Title) de la fenêtre de l’application.
**Fichier : MainWidget.cpp**. <br>
`this->setWindowTitle("Vinicius and Raquel TP");` ligne modifiée ;

### 2.3 ColorWidget : Faites en sorte que le champ ne soit pas modifiable.
**Fichier : MainWidget.cpp**. <br>
`_colorValueDisplay->setReadOnly(true);` ligne modifiée ;

### 2.4 Ajoutez un bouton (QPushButton) permettant de quitter l’application.
**Fichier : MainWidget.cpp**. <br>
`QPushButton * pushButtonQuiter = new QPushButton("Quit", this);`  
`pushButtonQuiter->setGeometry(260, 300, 160, 30);`  
`connect(pushButtonQuiter, &QPushButton::clicked, this, &MainWidget::onQuitPressed);`  
lignes modifiées

### 2.5 Ajoutez un second champ de saisie, non éditable, au dessus du champ déjà existant.
**Fichier : MainWidget.cpp**. <br>
`_mousePositionDisplay = new QLineEdit(this);`  
`_mousePositionDisplay->setReadOnly(true);`  
`_mousePositionDisplay->setGeometry(200, 160, 300, 30);`  
`_mousePositionDisplay->setAlignment(Qt::AlignHCenter);`

**Fichier : MainWidget.h**<br>
`QLineEdit * _mousePositionDisplay; /**< TP 1 2.5 */`  
Nous avons modifié toutes les positions en y des widgets.

### 2.6  Faites la modification de _mousePositionDisplay. Les coordonnées seront affichées avec un alignement (QLineEdit::setAlignment() W) à gauche, centré ou à droite selon le bouton de souris qui est appuyé.
**Fichier : MainWidget.h**  <br>
`#include <QMouseEvent>`  
...  
`protected:`  
` /**`  
`   * Gestionnaire d'événements pour les événements de mouvement de la souris.`  
`   */`  
`  virtual void mouseMoveEvent(QMouseEvent *event) override;`

`void updateMousePosition(const QPoint &pos, Qt::MouseButton button);`

**Fichier : MainWidget.cpp**.  <br>
```cpp
void MainWidget::updateMousePosition(const QPoint &pos, Qt::MouseButton button) {
  QString positionText = QString("(%1, %2)").arg(pos.x()).arg(pos.y());

  if (button == Qt::LeftButton) {
    _mousePositionDisplay->setAlignment(Qt::AlignLeft);
  } else if (button == Qt::RightButton) {
    _mousePositionDisplay->setAlignment(Qt::AlignRight);
  } else if (button == Qt::MiddleButton) {
    _mousePositionDisplay->setAlignment(Qt::AlignCenter);
  }

  _mousePositionDisplay->setText(positionText);

  _mousePositionDisplay->repaint();
}

void MainWidget::mouseMoveEvent(QMouseEvent *event) {
  Qt::MouseButton button = Qt::NoButton;
  if (event->buttons() & Qt::LeftButton) {
    button = Qt::LeftButton;
  } else if (event->buttons() & Qt::RightButton) {
    button = Qt::RightButton;
  } else if (event->buttons() & Qt::MiddleButton) {
    button = Qt::MiddleButton;
  }

  updateMousePosition(event->pos(), button);
}
```

### 3.1 À l’aide d’un objet de type QTimer capable d’émettre un signal de façon périodique.

### 3.2 Ajoutez les widgets nécessaires pour offrir un chronomètre (Start, Stop, Clear) à l’aide d’un second timer et d’un objet QElapsedTimer.
