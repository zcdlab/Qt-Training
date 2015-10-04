#include <QOpenGLWindow>
#include <QScreen>
#include <QPainter>
#include <QGuiApplication>
#include <QMatrix4x4>
#include <QStaticText>
#include <QKeyEvent>

#include "background_renderer.h"

class OpenGLWindow : public QOpenGLWindow {
  Q_OBJECT

public:
  OpenGLWindow();

protected:
  void paintGL() Q_DECL_OVERRIDE;
  void resizeGL(int w, int h) Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;

private:
  void setAnimating(bool enabled);

  QMatrix4x4 m_window_normalised_matrix;
  QMatrix4x4 m_window_painter_matrix;
  QMatrix4x4 m_projection;
  QMatrix4x4 m_view;
  QMatrix4x4 m_model_triangle;
  QMatrix4x4 m_model_text;
  QBrush m_brush;

  FragmentToy m_fragment_toy;
  QStaticText m_text_layout;
  bool m_animate;
};
