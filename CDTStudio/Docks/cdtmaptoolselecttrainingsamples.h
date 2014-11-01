#ifndef CDTMAPTOOLSELECTTRAININGSAMPLES_H
#define CDTMAPTOOLSELECTTRAININGSAMPLES_H

#include <qgsmaptool.h>

class QgsRubberBand;
class QToolBar;
class QComboBox;
class QSqlQueryModel;
class CDTMapToolSelectTrainingSamples : public QgsMapTool
{
    Q_OBJECT
public:
    explicit CDTMapToolSelectTrainingSamples(QgsMapCanvas *canvas,bool isReadOnly);
    ~CDTMapToolSelectTrainingSamples();

    void canvasMoveEvent( QMouseEvent * e );
    void canvasReleaseEvent( QMouseEvent * e );
signals:

public slots:
    void setSampleID(QUuid layerID);
//    void setReadOnly(bool readOnly);
    void clearRubberBand();
private:
    QUuid sampleID;    
    QgsMapCanvas *mapCanvas;
    QMap<qint64,QgsRubberBand*> rubberBands;
    bool mDragging;
//    bool mReadOnly;
    
    QToolBar *toolBar;
    QComboBox *comboBoxCategory;
    QSqlQueryModel *model;

    void updateRubber();
    void addSingleSample(qint64 id);
};

#endif // CDTMAPTOOLSELECTTRAININGSAMPLES_H
